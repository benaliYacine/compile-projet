%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.c"
    #include "int_pile.c"
    #include "expre_pile.c"
    #include "pgm_optimized.c"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    // int deb_else=0;
     StackNode_int *deb_else = NULL;
     StackNode_int *deb_while = NULL;
    int qc=0;
    // int Fin_if=0;
     StackNode_int *Fin_if = NULL;
     StackNode_int *Fin_while = NULL;
     StackNode_int *fin_routine = NULL;
     StackNode* Operandes_pile = NULL;
    char tmp [20];
    int nb_argument=0;
    extern char *type;
    char taille[20];
    StackNode_int *deb_for = NULL;
    StackNode_int *Fin_for = NULL;

%}

%union {
         int     entier;
         char*   str;
         float reel;
}
//kamel wech treturner f lexical hna 

%token <str>idf <str>str <str>character <entier>inti <reel>real mc_logi mc_data mc_end mc_code mc_integer verg mc_float mc_char mc_string mc_const mc_vector mc_read mc_display mc_if mc_else mc_for mc_not mc_true mc_false mc_and mc_or mc_g mc_l mc_ge mc_le mc_eq mc_di add sub mul divi aff mc_dowhile mc_enddo pvg deux_points crochet_ouv crochet_ferm po pf virg barre arobase err

//hna dir asociativite et la priorite lekher howa le plus prioritere
//9ader dir = right
%left mc_or mc_and // hada le plus prioritere
%left mc_l mc_g mc_ge mc_eq mc_di mc_le
%left add sub
%left mul divi

//bach dir definition lel les types ta3 les non terminaux
%type <str> TAILLE
%type <str> partie_gauch_affectation
%type <str> valeur
%type <str> EXPRE
%type <str> TERM
%type <str> OPERAND
%type <str> FACTOR
%type <str> EXPREt
%type <str> CONDI
%type <str> CONDIT
%type <str> LOGI
%type <str> var
%type <str> assignment
%type <str> for_statement


%% // soit dir start s beli l axiom howa s soit ma dirt howa par defaut ydi lewel kima hna s

s: idf mc_data DECS mc_end mc_code INSTS mc_end mc_end {YYACCEPT;}
;
VIDE:
;
TYPE: mc_integer | mc_float | mc_char | mc_logi | mc_string 
;
DECS: VIDE | ENSDEC
;
ENSDEC: ENSDEC DEC | DEC
;
DEC
    : TYPE deux_points ENSIDF_dec pvg
    | mc_const deux_points idf partie_gauch_affectation pvg {
    if(Declarer($3)){
        yyerror("Sementique error",$3,"est deja declare.");
    }

    StackNode* poppedElement = pop(&Operandes_pile);
    quadr("=", poppedElement->operande_name,"vide", $3);

    rechercher($3,"IDF"," ",$4,0," ",0);
            }
    | mc_vector deux_points idf crochet_ouv TAILLE deux_points TYPE crochet_ferm pvg {
        if(Declarer($3)){
            yyerror("Sementique error",$3,"est deja declare.");}
            rechercher($3,"IDF","TABLEAU",0,0,$5,0);
            initiali_tab($3,$5);

            char *tab_taille =strdup($5);
            char *tab_name=$3;


            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                quadr("Bounds", "0", strdup(operande_tmp->operande_name), "vide");
                token = strtok(NULL, ",");
            }
            quadr("ADEC", tab_name, "vide", "vide");
            // <==*   9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur 
            } 
;
partie_gauch_affectation: aff valeur {$$=$2;} | VIDE { $$=" ";}
;
ENSIDF_dec
    : ENSIDF_dec barre idf partie_gauch_affectation {
        if(Declarer($3)){
            yyerror("Sementique error",$3,"est deja declare.");
        }
        if(strcmp($4," ")!=0){
            if (!areCompatible(GetTypeFromTS($3), $4)) {
            yyerror("Sementique error","","incompatible type.");
        }
        // printf("\n\n------------yes they are compatible for the assignment\n\n");

            if (strstr(GetTypeFromTS($3),"TABLEAU")==NULL && !SetValInTS($3,$4)){
                yyerror("Sementique error",$3,",affectation non accepte.");
            }else{
                StackNode* poppedElement = pop(&Operandes_pile);
                quadr("=", poppedElement->operande_name,"vide", $3);
            }
        }

        rechercher($3,"IDF"," ",$4,0," ",0);
    }
| idf partie_gauch_affectation {
    
    if(Declarer($1)){
        yyerror("Sementique error",$1,"est deja declare.");
    }

    if(strcmp($2," ")!=0){
        if (!areCompatible(GetTypeFromTS($1), $2)) {
        yyerror("Sementique error","","incompatible type.");
    }
    // printf("\n\n------------yes they are compatible for the assignment\n\n");

        if (strstr(GetTypeFromTS($1),"TABLEAU")==NULL && !SetValInTS($1,$2)){
            yyerror("Sementique error",$1,",affectation non accepte.");
        }else{
            StackNode* poppedElement = pop(&Operandes_pile);
            quadr("=", poppedElement->operande_name,"vide", $1);
        }
    }
    rechercher($1,"IDF"," ",$2,0," ",0);   
}
; 

//ENSpara_arith: ENSpara_arith verg EXPRE | EXPRE // dert ENSpara_arith mechi dirakt sta3melt enspara parceque malazemch te9der dir parexemple true (logi) wla str tema dert hadi tmedlek ens des para arithme tema ghi les expr
//;
EXPRE
    :EXPRE mc_or CONDIT {
        if (isBoolean($1) && isBoolean($3)) {
            bool val1 = strcmp($1, "true") == 0;
            bool val2 = strcmp($3, "true") == 0;
            bool res = val1 | val2;
            // Conversion back to string is trivial here
            char *backToStr = res ? "true" : "false";


            StackNode* operande_tmp2 = pop(&Operandes_pile);
            StackNode* operande_tmp1 = pop(&Operandes_pile);
            char *res_tmp = strdup(Cree_temp_cond());
            push(&Operandes_pile, "EXPRE", res_tmp, "LOGICAL");
            createQuadLogic (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
            $$=backToStr;
        }
        else {
            yyerror("Sementique error","","cannot use or with non boolean operands");
        }
    }
    | EXPRE mc_and CONDIT{
        if (isBoolean($1) && isBoolean($3)) {
            bool val1 = strcmp($1, "true") == 0;
            bool val2 = strcmp($3, "true") == 0;
            bool res = val1 & val2;
            // Conversion back to string is trivial here
            char *backToStr = res ? "true" : "false";
            
            
            StackNode* operande_tmp2 = pop(&Operandes_pile);
            StackNode* operande_tmp1 = pop(&Operandes_pile);
            char *res_tmp = strdup(Cree_temp_cond());
            push(&Operandes_pile, "EXPRE", res_tmp, "LOGICAL");
            createQuadLogic (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
            $$=backToStr;
        }
        else {
            yyerror("Sementique error","","cannot use and with non boolean operands");
        }
    } 
    | CONDIT {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPRE", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    }
;
    CONDIT
    : CONDIT mc_l EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (5,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(ltEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT mc_g EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (6,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(gtEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT mc_ge EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(geEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT mc_eq EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (1,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                $$=strdup(eqEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 



    } 
    | CONDIT mc_di EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(neEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT mc_le EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (4,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                
        $$=strdup(leEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    }
    | EXPREt {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "CONDIT", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
        }
;
EXPREt
    : EXPREt add TERM   {   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("+",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "EXPREt", T, type);



        $$=strdup(addEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 
        // printf("\n\n------------res= %s\n\n",addEntities($1,$3));
        
        
    } 
    | EXPREt sub TERM {   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("-",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "EXPREt", T, type);



        $$=strdup(subEntities($1,$3));
    } 
    | TERM {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPREt", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    }
;
TERM
    : TERM mul FACTOR {   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("*",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "TERM", T, type);


        $$=strdup(mulEntities($1,$3));

    } 
    | TERM divi FACTOR {
        if(isEntityZero($3)){
            printf("\n\n------------division sur zero. $3= %s\n\n",$3);
            yyerror("Sementique error","","division sur zero.");
        }else {
            if (!canPerformArithmetic($1, $3)) {
                yyerror("Sementique error","","incompatible type");
            }  



            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);

            char *T=strdup(Cree_temp());

            quadr("/",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

            char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

            push(&Operandes_pile, "TERM", T, type);



            $$=strdup(divEntities($1,$3));
        } 
    }
    | FACTOR {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    }
    ;

FACTOR
    : po EXPRE pf { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        $$=$2;
        }
    | OPERAND { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    
    }
    | mc_not FACTOR{   
        if (!isBoolean($2)) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "FACTOR", res_tmp, "LOGICAL");
        createQuadLogic(1,operande_tmp1->operande_name,"vide",res_tmp);

        $$=strdup(notEntities($2));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    ;

OPERAND
    :
    idf {
        if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare.");
        }
        char *res=strdup(GetValFromTS($1));
        char *type=strdup(GetTypeFromTS($1));// wela 9ader tejbed e type mel val b GetTypeFromVal mais ana seyiit nkhali koulech kima derna fel cour
        // printf("\n\n------------val ta3 idf= %s\n\n",res);
        if ((res==NULL || strcmp(res," ")==0) && (strstr(type, "ARGUMENT") == NULL)){
            yyerror("Sementique error",$1,"n'a pas d'une valeur");
        } else{
            push(&Operandes_pile, "OPERAND", strdup($1), type);
            $$=strdup(res);
        }
    }
    | LOGI {
        push(&Operandes_pile, "OPERAND", $1, "LOGICAL");
        $$=$1;
    }

    | inti {
        char backToStr[20];
        sprintf(backToStr, "%d", $1);
        // printf("\npushed inti: %s \n", backToStr);
        push(&Operandes_pile, "OPERAND", strdup(backToStr), "INTEGER");
        $$=strdup(backToStr);
    }

    | real {
        char backToStr[20];
        sprintf(backToStr, "%g", $1);
        push(&Operandes_pile, "OPERAND", backToStr, "FLOAT");
        $$=strdup(backToStr);
    }
    | idf crochet_ouv TAILLE crochet_ferm {
        
        if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare.");      
        }
        if(!verifier_in_out_table($1,$3))
            yyerror("Sementique error","","out of rang"); 
        //strcpy(taille,$3);
        char table[100];
        char *tab_taille =strdup($3);
        // printf("\n-----------------------------------------taille:%s\n",tab_taille);
        


        char final_str[1024] = "";
        char temp[1024];
        int firstElement = 1;

        char *token = strtok(tab_taille, ",");
        while (token != NULL) {

            StackNode* operande_tmp = pop(&Operandes_pile);
            if (firstElement) {
                // For the first element, directly copy it to final_str
                snprintf(final_str, sizeof(final_str), "%s", operande_tmp->operande_name);
                firstElement = 0; // Set the flag to 0 as the first element is added
            } else {
                // For subsequent elements, add a comma before the element
                snprintf(temp, sizeof(temp), "%s,%s",operande_tmp->operande_name, final_str);
                strcpy(final_str, temp); // Copy the temporary string back to final_str
            }
            token = strtok(NULL, ",");
        }

        sprintf(table, "%s(%s)", $1, final_str);
        push(&Operandes_pile, "OPERAND", table, GetTypeFromTS($1));
        $$=return_val_tab($1,$3);
    }  //9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur
;
TAILLE
    : TAILLE verg valeur {
        if(!isInteger($3)){
            yyerror("Sementique error",$3,"n'est pas un entier");
        }
        if(strtol($3, NULL, 10)<0){
            yyerror("Sementique error",$3,"est negative");
        }
        
        char* final_str = malloc(strlen($1) + strlen($3) + 4 + 1);
        sprintf(final_str, "%s,%s", $1, $3);
        // printf("\n-----------------------------------------final str ta3 TAILLE MOR SPRINTF:%s\n",final_str);
        $$=strdup(final_str);
        // printf("\n-----------------------------------------str ta3 $$ TAILLE:%s\n",$$);
    } 
    | valeur {
        if(!isInteger($1)){
            yyerror("Sementique error",$1,"n'est pas un entier");
        }
        if(strtol($1, NULL, 10)<0){
            yyerror("Sementique error",$1,"est negative");
        }
        
        $$=strdup($1);
    }
;
LOGI: mc_true {$$=strdup("true");}
    | mc_false {$$=strdup("false");}
;
INSTS: VIDE | ENSINST
;
ENSINST: ENSINST INST | INST
;
INST: if_statement | read_statement | write_statement | dowhile_statement | assignment | for_statement
;
var
    : idf {
        if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare.");
        }
        char *type=strdup(GetTypeFromTS($1));
        push(&Operandes_pile, "OPERAND", strdup($1), type);
        $$=strdup($1);
    }
    | idf po TAILLE pf {
        // printf("\n-----------------------------------------taille ta3 $3 1:%s\n",$3);
        if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare."); 
        }
        if(!verifier_in_out_table($1,$3)){
            yyerror("Sementique error","","out of rang"); 
        }

        char table[100];
        char *tab_taille =strdup($3);
        char final_str[1024] = "";
        char temp[1024];
        int firstElement = 1;

        char *token = strtok(tab_taille, ",");
        while (token != NULL) {

            StackNode* operande_tmp = pop(&Operandes_pile);
            if (firstElement) {
                // For the first element, directly copy it to final_str
                snprintf(final_str, sizeof(final_str), "%s", operande_tmp->operande_name);
                firstElement = 0; // Set the flag to 0 as the first element is added
            } else {
                // For subsequent elements, add a comma before the element
                snprintf(temp, sizeof(temp), "%s,%s",operande_tmp->operande_name, final_str);
                strcpy(final_str, temp); // Copy the temporary string back to final_str
            }
            token = strtok(NULL, ",");
        }

        sprintf(table, "%s(%s)", $1, final_str);
        push(&Operandes_pile, "OPERAND", table, GetTypeFromTS($1));


        $$=$1;
        
        strcpy(taille,$3);
        // printf("\n-----------------------------------------taille ta3 $3 2:%s\n",taille);
    }
;
if_statement: B_if else_clause mc_end{
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_if),1,tmp);
    printf("pgm juste");
}
;
B_if: A_if deux_points INSTS{
    // Fin_if=qc;
    push_int(&Fin_if, qc);
    quadr("BR", "","vide", "vide");
    sprintf(tmp,"%d",qc); // transformer entier vers string
    ajour_quad(pop_int(&deb_else),1,tmp);
}
;
A_if: mc_if po CONDI pf{
    // deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
    push_int(&deb_else, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
}
;
else_clause: mc_else deux_points INSTS | VIDE
;
assignment
    : var aff valeur pvg {
        if (strcmp(GetTypeFromTS($1), "CONST") == 0) {
            yyerror("Sementique error","","constantes are not assignable.");
        }
        if (!areCompatible(GetTypeFromTS($1), $3)) {
            yyerror("Sementique error","","incompatible type.");
        }
        // printf("\n\n------------yes they are compatible for the assignment\n\n");
        if(strstr(GetTypeFromTS($1),"TABLEAU")!=NULL){
            A_M_tab($1, taille, $3);
            char table[100];

        }else {
            if (!SetValInTS($1,$3)){
                yyerror("Sementique error",$1,",affectation non accepte.");
            }
        }

        StackNode* operande_tmp = pop(&Operandes_pile);
        StackNode* poppedElement_var = pop(&Operandes_pile);
        
        quadr("=", operande_tmp->operande_name,"vide", poppedElement_var->operande_name);
        $$=$1;
    } //OGassi operande gauche d'afectation 
;
valeur
    : str {
        push(&Operandes_pile, "valeur", $1, "STRING");
        $$=strdup($1);
    } //valeur ay haja 3andha valeur true false 5 4 7 "dfsakl" max(5)
    | character {
        push(&Operandes_pile, "valeur", $1, "CHAR");
        $$=strdup($1);
    }
    | EXPRE {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    } // hna expre rafda valeur belmiis true wela 5 3la chakl string
;
read_statement: mc_read po str deux_points arobase var pf pvg
{
    StackNode* operande_tmp = pop(&Operandes_pile);
    // Check if $3 is exactly one of the format strings
    char* format = $3;
    if (strcmp(format, "\"$\"") != 0 && 
        strcmp(format, "\"%\"") != 0 && 
        strcmp(format, "\"#\"") != 0 && 
        strcmp(format, "\"&\"") != 0) {
        yyerror("Semantic error", format, "is not a valid format sign. Use $ % # or &");
    }
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS($6);
    char* expectedType = NULL;
    
    // Determine expected type based on format
    if (strcmp(format, "\"$\"") == 0)
        expectedType = "INTEGER";
    else if (strcmp(format, "\"%\"") == 0)
        expectedType = "FLOAT";
    else if (strcmp(format, "\"#\"") == 0)
        expectedType = "STRING";
    else if (strcmp(format, "\"&\"") == 0)
        expectedType = "CHAR";
    
    // Check if variable type matches expected type
    if (strcmp(varType, expectedType) != 0) {
        // For constants, check the value type
        if (strcmp(varType, "CONST") == 0) {
            char* typeFromVal = GetTypeFromVal(GetValFromTS($6));
            if (strcmp(typeFromVal, expectedType) != 0) {
                yyerror("Semantic error", format, "does not match variable type");
            }
        } else {
            yyerror("Semantic error", format, "does not match variable type");
        }
    }
    quadr("READ", format, operande_tmp->operande_name, "vide");
}
;
write_statement: mc_display po str deux_points var pf pvg 
{
    StackNode* operande_tmp = pop(&Operandes_pile);
    // Check if the string contains one of the format signs at the end
    char* message = $3;
    int len = strlen(message);
    
    // Check if string ends with a format sign
    if (len < 3) {
        yyerror("Semantic error", message, "does not contain a format sign");
    }
    
    char formatChar = message[len-2]; // Get the character before the closing quote
    char formatStr[2];
    
    //for yyerror
    formatStr[0] = formatChar;
    formatStr[1] = '\0';

    // Verify format sign is valid
    if (formatChar != '$' && formatChar != '%' && formatChar != '#' && formatChar != '&') {
        yyerror("Semantic error", message, "does not end with a valid format sign ($ % # &)");
    }
    
    
    
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS($5);
    char* expectedType = NULL;
    // Determine expected type based on format
    if (formatChar == '$')
        expectedType = "INTEGER";
    else if (formatChar == '%')
        expectedType = "FLOAT";
    else if (formatChar == '#')
        expectedType = "STRING";
    else if (formatChar == '&')
        expectedType = "CHAR";
    // Check if variable type matches expected type
    if (strcmp(varType, expectedType) != 0) {
        // For constants, check the value type
        if (strcmp(varType, "CONST") == 0) {
            char* typeFromVal = GetTypeFromVal(GetValFromTS($5));
            if (strcmp(typeFromVal, expectedType) != 0) {
                yyerror("Semantic error", formatStr, "does not match variable type");
                
            }
        } else {
            yyerror("Semantic error", formatStr, "does not match variable type");
            
        }
    }
    printf("\n-----------------------------------------message ta3 $3:%s\n",message);
    // Create display message without format character but keep quotes
    char* displayMessage = (char*)malloc(len); // -1 for removing just the format char
    if (displayMessage == NULL) {
        yyerror("Semantic error", "memory allocation", "failed for display message");
    }
    // Copy the message up to but not including the format character
    strncpy(displayMessage, message, len - 2);
    // Add the closing quote
    displayMessage[len - 2] = '"';
    displayMessage[len - 1] = '\0';

    quadr("x", displayMessage, operande_tmp->operande_name, "vide");
    free(displayMessage);
}
| mc_display po str pf pvg
{
    quadr("WRITE", $3, "vide", "vide");
}
;
dowhile_statement: B_while INSTS mc_enddo{
    sprintf(tmp,"%d",pop_int(&deb_while));
    quadr("BR", tmp,"vide", "vide");
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_while),1,tmp);
}
;
B_while: A_while po CONDI pf{
    push_int(&Fin_while, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
}
;
A_while: mc_dowhile{
    push_int(&deb_while, qc);
}
;
CONDI
    : EXPRE {
        if (isBoolean($1)) {
            $$=$1;
        } else {
            yyerror("Sementique error",$1,"is not boolean");
        }
    }
;

for_statement: A_for INSTS mc_end {
    // Go back to loop condition
    sprintf(tmp, "%d", pop_int(&deb_for));
    quadr("BR", tmp, "vide", "vide");
    
    // Update the exit jumps
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_for), 1, tmp);
}
;

A_for: mc_for po idf deux_points valeur deux_points CONDI pf {
    StackNode* operande_tmp = pop(&Operandes_pile);
    
    // Check if the counter variable is declared
    if(!Declarer($3)){
        yyerror("Sementique error", $3, "est non declare.");
    }
    
    // Check if the step is valid (integer)
    if(!isInteger($5)){
        yyerror("Sementique error", $5, "n'est pas un entier valide pour le pas.");
    }
    
    // Initialize counter variable with the step value
    char *T = strdup(Cree_temp());
    quadr("=", $5, "vide", T);
    quadr("+", $3, T, $3);
    
    // Store position for loop condition
    push_int(&deb_for, qc);
    
    // Evaluate condition
    operande_tmp = pop(&Operandes_pile);
    
    // Create conditional jump to exit loop if condition is false
    push_int(&Fin_for, qc);
    quadr("BZ", "", operande_tmp->operande_name, "vide");
}
;

%%

int main(int argc, char** argv)
{
    if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            // Handle error
            perror("Cannot open example.txt");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    yyparse(); // la fct qui lance l analyseur syntaxique
    // yylex(); // lance lexical
    afficher();
    afficher_qdr();

    apply_all_optimizations();
    generate_assembly("output.asm");

    if (yyin != stdin) {
        fclose(yyin);
    }
    afficher_pile(Operandes_pile);
    
   return 0;
 }
 yywrap ()
 {}

// int yyerror ( char*  msg )
//  {
//     printf("File \"%s\", line %d, character %d: %s\n",file_name, nb_ligne, Col,msg);
//     exit(EXIT_FAILURE);
//   }
int yyerror ( char*  msg, char* entite, char* description)
 {
    afficher();
    afficher_qdr();
    afficher_pile(Operandes_pile);
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    exit(EXIT_FAILURE);
  }
