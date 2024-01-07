%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.c"
    #include "int_pile.c"
    #include "str_pile.c"
    #include "expre_pile.c"
    #include "fct_etiq.c"
    #include "pgm.c"
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

%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token <str>idf aff mc_prgrm mc_rtin <entier>inti <reel>real mc_endr mc_call mc_dim mc_logi mc_char mc_true mc_false mc_read mc_write pvg <str>str mc_int mc_real mc_end mc_if mc_then mc_else mc_dowhile mc_enddo mc_equival mc_or ge eq ne le add sub mul divi mc_and mc_endif lt gt po pf verg err 
%left lt gt ge eq ne le
%left add sub
%left mul divi
%left mc_or mc_and


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
%type <str> ENSpara
%type <str> assignment
%type <str> debut_fct


%%
s: FCTS PRGM_PRIN {YYACCEPT;}
;
PRGM_PRIN: mc_prgrm idf DECS INSTS mc_end
;
FCTS: VIDE | ENSFCT
;
VIDE:
;
ENSFCT: ENSFCT FCT | FCT
;
FCT
    : debut_fct ENSINST assignment mc_endr {
        if(strcmp($1,$3)!=0){
            yyerror("Sementique error",$3,"est different du nom de la fonction.");
        }
    }
    | debut_fct assignment mc_endr {
        if(strcmp($1,$2)!=0){
            yyerror("Sementique error",$2,"est different du nom de la fonction.");
        }
    }

;
debut_fct
    : TYPE mc_rtin idf po IDFS pf DECS {
        //R1
        // int p = lookup($3);
        // printf("r1 look up p:%d\n",p);
        
        // if (p==-1){
        //     p=inserer_fct($3,false,0);
        //     printf("r1 inserer_fct p:%d\n",p);
        //     show_table();
        // }else{
        //     yyerror("Sementique error",$3,"est deja declare.");
        // }
        //R3
        // int p2 = lookup($3);
        // printf("r3 look up p:%d\n",p2);
        // int a,b;
        // if (p2==-1){
        //     yyerror("Sementique error",$3,"est non declare.1");
        // }else{
        //     if(table_fct[p2].util){
        //         yyerror("Sementique error",$3,"est deja declare.");
        //     }else{
        //         a = table_fct[p2].address;
        //         while(a!=0){
        //             b= strtol(quad[a].op1, NULL, 10);
        //             sprintf(tmp,"%d",qc);
        //             ajour_quad(a,1,tmp);
        //             a=b;
        //         }
        //         table_fct[p2].address=qc;
        //     }
        // }
        //R3 fin
        Declarer($3);
        inserer_fonction($3,nb_argument);
        nb_argument=0;
        $$=$3;
}
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
DECS: VIDE | ENSDEC
;
ENSDEC: ENSDEC DEC | DEC
;
DEC
    : TYPE ENSIDF_dec pvg | TYPE idf mul inti pvg {
        // printf("the dcr idf is :%s\n",$2);
        if(Declarer($2)){
            yyerror("Sementique error",$2,"est deja declare.");
        }
    }
    | TYPE idf mc_dim po TAILLE pf pvg {
        if(Declarer($2)){
            yyerror("Sementique error",$2,"est deja declare.");}
            rechercher($2,"IDF","TABLEAU",0,0,$5,0);
            initiali_tab($2,$5);

            char *tab_taille =strdup($5);
            char *tab_name=$2;


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
    : ENSIDF_dec verg idf partie_gauch_affectation {
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
    : CONDIT lt EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
        }   


        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (5,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(ltEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT gt EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (6,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(gtEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT ge EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(geEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT eq EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (1,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                $$=strdup(eqEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 



    } 
    | CONDIT ne EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        $$=strdup(neEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    } 
    | CONDIT le EXPREt{   
        if (!canPerformArithmetic($1, $3)) {
            yyerror("Sementique error","","incompatible type.");
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
            yyerror("Sementique error","","incompatible type.");
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
            yyerror("Sementique error","","incompatible type.");
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
            yyerror("Sementique error","","incompatible type.");
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
            yyerror("Sementique error","","division sur zero.");
        }else {
            if (!canPerformArithmetic($1, $3)) {
                yyerror("Sementique error","","incompatible type.");
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
        push(&Operandes_pile, "OPERAND", backToStr, "REAL");
        $$=strdup(backToStr);
    }

    | idf po TAILLE pf {
        
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

    | mc_call idf po ENSpara pf {
        //R2
        // show_table();
        // int p = lookup($2);
        // printf("r2 look up p:%d\n",p);
        // if (p==-1){
        //     yyerror("Sementique error",$3,"est non declare.2");
        // }else{
        //     if(table_fct[p].util){
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //     }else{
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //         table_fct[p].address=qc;
        //     }
        //     push_int(&fin_routine, qc);
        // }

        //R2 fin 
        if(verifier_nb_argument($2,nb_argument)==1){
            yyerror("Sementique error","","le nombre d'argument est uncorrect.");
        }else if(verifier_nb_argument($2,nb_argument)==-1)
            yyerror("Sementique error",$2,"est non declare.");
        char *tab_taille =strdup($4);
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

        char fonct[100];
        sprintf(fonct, "%s(%s)", $2, final_str);
        push(&Operandes_pile, "OPERAND", fonct, GetTypeFromTS($2));

        $$=return_val_fonction($2);nb_argument=0;
    } // enspara parceque te9der t3ayat l fct b ay haja mouhim treja3 valeur 
;

ENSpara
    : ENSpara verg valeur {
        char* final_str = malloc(strlen($1) + strlen($3) + 4 + 1);
        sprintf(final_str, "%s,%s", $1, $3);
        $$=strdup(final_str);
        nb_argument++;
    } 
    | valeur {
        $$=strdup($1);
        nb_argument++;}
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
IDFS: ENSIDF | VIDE
;
ENSIDF: ENSIDF verg idf {Declarer($3);nb_argument++;} | idf {Declarer($1);nb_argument++;}
;
INSTS: VIDE | ENSINST
;
ENSINST: ENSINST INST | INST
;
INST: if_statement | read_statement | write_statement | dowhile_statement | assignment | eqival_statement
;
eqival_statement : mc_equival ens_list_vars pvg
;
ens_list_vars: ens_list_var | VIDE
;
ens_list_var: ens_list_var verg po list_var pf | po list_var pf
;
list_var
    : list_var verg var {
        StackNode* operande_tmp = pop(&Operandes_pile);
    }
    | var{
        StackNode* operande_tmp = pop(&Operandes_pile);
    }
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
if_statement: B_if else_clause mc_endif{
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_if),1,tmp);
    printf("pgm juste");
}
;
B_if: A_if mc_then ENSINST{
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
else_clause: mc_else ENSINST | VIDE
;
assignment
    : var aff valeur pvg {   
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
        push(&Operandes_pile, "valeur", $1, "CHARACTER");
        $$=strdup($1);
    } //valeur ay haja 3andha valeur true false 5 4 7 "dfsakl" max(5)
    | EXPRE {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    } // hna expre rafda valeur belmiis true wela 5 3la chakl string
;
read_statement: mc_read po var pf pvg{StackNode* operande_tmp = pop(&Operandes_pile);} // kanet idf fi blaset var dertha ha ka parceque 9ader ydir read(t(5)); nafs echi f write var mechi idf
;
write_statement: mc_write po ENS_PARA_WRITE pf pvg 
;
ENS_PARA_WRITE: ENS_PARA_WRITE verg str | ENS_PARA_WRITE verg var{StackNode* operande_tmp = pop(&Operandes_pile);} | str | var{StackNode* operande_tmp = pop(&Operandes_pile);}
;
dowhile_statement: B_while ENSINST mc_enddo{
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

%%

int main(int argc, char** argv)
{
    if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            // Handle error
            perror("Cannot open input_file.txt");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    yyparse();
    yylex();
    afficher();
    afficher_qdr();
    
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
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    exit(EXIT_FAILURE);
  }
