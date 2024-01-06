%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.c"
    #include "int_pile.c"
    #include "expre_pile.c"
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

%token <str>idf aff mc_prgrm mc_rtin <entier>inti <reel>real mc_endr mc_call mc_dim mc_logi mc_char mc_true mc_false mc_read mc_write pvg <str><str>str mc_int mc_real mc_end mc_if mc_then mc_else mc_dowhile mc_enddo mc_equival mc_or ge eq ne le add sub mul divi mc_and mc_endif lt gt po pf verg err 
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
FCT: TYPE mc_rtin idf po IDFS pf DECS ENSINST assignment mc_endr {Declarer($3);inserer_fonction($3,nb_argument);nb_argument=0;}  | TYPE mc_rtin idf po IDFS pf  DECS assignment mc_endr {inserer_fonction($3,nb_argument);nb_argument=0;}
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
DECS: VIDE | ENSDEC
;
ENSDEC: ENSDEC DEC | DEC
;
DEC: TYPE ENSIDF_dec pvg | TYPE idf {printf("the dcr idf is :%s\n",$2);if(Declarer($2)){

        yyerror("Sementique error",$2,"est deja declare.");
    }} mul inti pvg 
    | TYPE idf mc_dim po TAILLE pf pvg {if(Declarer($2)){
        yyerror("Sementique error",$2,"est deja declare.");}
        rechercher($2,"IDF","TABLEAU",0,0,$5,0);
        initiali_tab($2,$5);
          // <==*   9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur 
        } 
;
partie_gauch_affectation: aff valeur {$$=$2;} | VIDE { $$=" ";}
;
ENSIDF_dec: ENSIDF_dec verg idf partie_gauch_affectation {
    if(Declarer($3)){
        yyerror("Sementique error",$3,"est deja declare.");
    }

    rechercher($3,"IDF"," ",$4,0," ",0);
}
| idf partie_gauch_affectation {
    
    if(Declarer($1)){
        yyerror("Sementique error",$1,"est deja declare.");
    }
    rechercher($1,"IDF"," ",$2,0," ",0);   
}
; 
TAILLE: TAILLE verg inti {  if($3<0){
                            yyerror("Sementique error","","taille negative");
                                    }
                                char* str_inti;
                                // Allocate memory for str_inti
                                str_inti = malloc(12 * sizeof(char)); // 12 is an example size, adjust as needed

                                sprintf(str_inti, "%d", $3);
                                // printf("----------------%s\n", str_inti);
                                
                                
                                char* final_str = malloc(strlen($1) + strlen(str_inti) + 4 + 1);
                                sprintf(final_str, "%s,%s", $1, str_inti);
                                $$=final_str;
    }
        | inti {
                    if($1<0){
                            yyerror("Sementique error","","taille negative");
                                    }
                                char* str_inti;
                                // Allocate memory for str_inti
                                str_inti = malloc(12 * sizeof(char)); // 12 is an example size, adjust as needed

                                sprintf(str_inti, "%d", $1);
                                // printf("----------------%s\n", str_inti);

                                $$=str_inti;}     //kouna nekhedmou biha hna <==* fi blaset ENSpara w raja3naha w manb3d na7oha
;
//ENSpara_arith: ENSpara_arith verg EXPRE | EXPRE // dert ENSpara_arith mechi dirakt sta3melt enspara parceque malazemch te9der dir parexemple true (logi) wla str tema dert hadi tmedlek ens des para arithme tema ghi les expr
//;
EXPRE
    : EXPRE lt EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   


            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);


                            $$=strdup(ltEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

                        } 
    | EXPRE gt EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   
                            


            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);
                            
                            $$=strdup(gtEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

                        } 
    | EXPRE ge EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   
                            
            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);
                            
                            $$=strdup(geEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

                        } 
    | EXPRE eq EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   
                            
                            
            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);
                            $$=strdup(eqEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 



                        } 
    | EXPRE ne EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   

            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);
                            
                            $$=strdup(neEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

                        } 
    | EXPRE le EXPREt{   if (!canPerformArithmetic($1, $3)) {
                                yyerror("Sementique error","","incompatible type.");
                            }   
                            
            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);
                            
                            $$=strdup(leEntities($1,$3));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

                        } 
    | EXPREt {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPRE", poppedElement->operande_name, poppedElement->operande_type);
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
        printf("\n\n------------res= %s\n\n",addEntities($1,$3));
        
        
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
            }char *res=GetValFromTS($1);
            printf("\n\n------------val ta3 idf= %s\n\n",res);
            if (res==NULL || res==" "){
                yyerror("Sementique error",$1,"n'a pas d'une valeur");
            } else{
                char *type=strdup(GetTypeFromTS($1));// wela 9ader tejbed e type mel val b GetTypeFromVal mais ana seyiit nkhali koulech kima derna fel cour
                push(&Operandes_pile, "OPERAND", $1, type);
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
            push(&Operandes_pile, "OPERAND", backToStr, "INTEGER");
            $$=strdup(backToStr);
}

    | real {
            char backToStr[20];
            sprintf(backToStr, "%g", $1);
            push(&Operandes_pile, "OPERAND", backToStr, "REAL");
            $$=strdup(backToStr);
}

    | idf po TAILLE pf {{if(!Declarer($1)){
        yyerror("Sementique error",$1,"est non declare.");      
    }}if(!verifier_in_out_table($1,$3))yyerror("Sementique error","","out of rang"); 
    //strcpy(taille,$3);
    
     $$=return_val_tab($1,$3);}  //9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur

    | mc_call idf po ENSpara pf {if(verifier_nb_argument($2,nb_argument)){yyerror("Sementique error","","le nombre d'argument est uncorrect.");}else {$$="1";nb_argument=0;}} // enspara parceque te9der t3ayat l fct b ay haja mouhim treja3 valeur 
;

ENSpara: ENSpara verg valeur {nb_argument++;} | valeur {nb_argument++;}
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
list_var: list_var verg var | var
;
var: idf 
    {
        if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare.");
            $$=$1;
        }
    }
    | idf po TAILLE pf {if(!Declarer($1)){
            yyerror("Sementique error",$1,"est non declare."); 
    }
            if(!verifier_in_out_table($1,$3))yyerror("Sementique error","","out of rang"); 
        $$=$1;
        strcpy(taille,$3);
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
A_if:mc_if po CONDI pf{
    // deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
    push_int(&deb_else, qc);
    quadr("BZ", "","temp_cond", "vide");
}
;
else_clause: mc_else ENSINST | VIDE
;
assignment: var aff valeur pvg  {   if (!areCompatible(GetTypeFromTS($1), $3)) {
                                        yyerror("Sementique error","","incompatible type.");
                                    }
                                    printf("\n\n------------yes they are compatible for the assignment\n\n");
                                    if (strstr(GetTypeFromTS($1),"TABLEAU")==NULL&&!SetValInTS($1,$3)){
                                        yyerror("Sementique error",$1,",affectation non accepte.");
                                    }
                                    if(strstr(GetTypeFromTS($1),"TABLEAU")!=NULL){
                                        A_M_tab($1, taille, $3);
                                    }
        StackNode* poppedElement = pop(&Operandes_pile);
        quadr("=", poppedElement->operande_name,"vide", $1);
    } //OGassi operande gauche d'afectation 
;
valeur
    : str {
        push(&Operandes_pile, "valeur", $1, "CHARACTER");
        $$=strdup(GetValFromTS($1));
    } //valeur ay haja 3andha valeur true false 5 4 7 "dfsakl" max(5)
    | EXPRE {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        $$=$1;
    } // hna expre rafda valeur belmiis true wela 5 3la chakl string
;
read_statement: mc_read po var pf pvg // kanet idf fi blaset var dertha ha ka parceque 9ader ydir read(t(5)); nafs echi f write var mechi idf
;
write_statement: mc_write po ENS_PARA_WRITE pf pvg 
;
ENS_PARA_WRITE: ENS_PARA_WRITE verg str | ENS_PARA_WRITE verg var | str | var
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
    quadr("BZ", "","temp_cond", "vide");
}
;
A_while: mc_dowhile{
    push_int(&deb_while, qc);
}
;
CONDI: CONDI mc_or CONDI {if (isBoolean($1) && isBoolean($3)) {
        bool val1 = strcmp($1, "true") == 0;
        bool val2 = strcmp($3, "true") == 0;
        bool res = val1 | val2;
        // Conversion back to string is trivial here
        char *backToStr = res ? "true" : "false";
        $$=backToStr;
    }
    else {
        yyerror("Sementique error","","cannot use or with non boolean operands");
    }}
    | CONDI mc_and CONDIT{if (isBoolean($1) && isBoolean($3)) {
        bool val1 = strcmp($1, "true") == 0;
        bool val2 = strcmp($3, "true") == 0;
        bool res = val1 & val2;
        // Conversion back to string is trivial here
        char *backToStr = res ? "true" : "false";
        $$=backToStr;
    }
    else {
        yyerror("Sementique error","","cannot use or with non boolean operands");
    }} 
    | CONDIT {if (isBoolean($1)) {
        $$=$1;
    }
    else {
        yyerror("Sementique error",$1,"is not boolean");
    }}
;
CONDIT: EXPRE {if (isBoolean($1)) {
        $$=$1;
    }
    else {
        yyerror("Sementique error",$1,"is not boolean");
    }}
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


