%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.h"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    char* tmp;
    int k;
    int nb_argument=0;

%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token <str>idf aff mc_prgrm mc_rtin <entier>inti <reel>real mc_endr mc_call mc_dim mc_logi mc_char mc_true mc_false mc_read mc_write pvg str mc_int mc_real mc_end mc_if mc_then mc_else mc_dowhile mc_enddo mc_equival mc_or ge eq ne le add sub mul divi mc_and mc_endif lt gt po pf verg err 

%left add sub
%left mul divi
%left mc_or mc_and

%type <str> TAILLE
%type <reel> partie_gauch_affectation
%type <reel> valeur
%type <reel> EXPRE
%type <reel> TERM
%type <reel> OPERAND
%type <reel> FACTOR


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
FCT: TYPE mc_rtin idf po IDFS pf DECS ENSINST assignment mc_endr {inserer_fonction($3,nb_argument);nb_argument=0;}  | TYPE mc_rtin idf po IDFS pf  DECS assignment mc_endr {inserer_fonction($3,nb_argument);nb_argument=0;}
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
DECS: VIDE | ENSDEC
;
ENSDEC: ENSDEC DEC | DEC
;
DEC: TYPE ENSIDF_dec pvg | TYPE idf {if(!Declarer($2)){
        Col-=2;
        yyerror("Sementique erreur");
    }} mul inti pvg 
    | TYPE idf mc_dim po TAILLE pf pvg {if(!Declarer($2)){
        yyerror("Sementique erreur");}rechercher($2,"IDF","TABLEAU",0,0,$5,0);}   // <==*   9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur 
;
partie_gauch_affectation: aff valeur {$$=$2;} | VIDE { $$=0;}
;
ENSIDF_dec: ENSIDF_dec verg idf partie_gauch_affectation {
    if(!Declarer($3)){
        Col-=2;
        yyerror("Sementique erreur");
    }
    rechercher($3,"IDF"," ",$4,0," ",0);
}
| idf partie_gauch_affectation {
    if(!Declarer($1)){
        Col-=2;
        yyerror("Sementique erreur");
        
    }
    rechercher($1,"IDF"," ",$2,0," ",0);
}
; 
TAILLE: TAILLE verg inti {
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
                                char* str_inti;
                                // Allocate memory for str_inti
                                str_inti = malloc(12 * sizeof(char)); // 12 is an example size, adjust as needed

                                sprintf(str_inti, "%d", $1);
                                // printf("----------------%s\n", str_inti);

                                $$=str_inti;
    }     //kouna nekhedmou biha hna <==* fi blaset ENSpara w raja3naha w manb3d na7oha
;
//ENSpara_arith: ENSpara_arith verg EXPRE | EXPRE // dert ENSpara_arith mechi dirakt sta3melt enspara parceque malazemch te9der dir parexemple true (logi) wla str tema dert hadi tmedlek ens des para arithme tema ghi les expr
//;
EXPRE
    : EXPRE add TERM {$$=$1+$2;} 
    | EXPRE sub TERM {$$=$1-$2;}
    | TERM {$$=$1;}
    ;

TERM
    : TERM mul FACTOR {$$=$1*$2;}
    | TERM divi FACTOR {if($3==0){yyerror("Sementique erreur");}else $$=$1/$2;}
    | FACTOR {$$=$1;}
    ;

FACTOR
    : po EXPRE pf {$$=$2;}
    | OPERAND {$$=$1;}
    ;

OPERAND
    :  idf {{if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} $$=0;}
    | LOGI { $$=0;}
    | inti {$$=(float)$1;}
    | real {$$=$1;}
    | idf po TAILLE pf {{if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} $$=0;}  //9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur
    | mc_call idf po ENSpara pf {if(verifier_nb_argument($2,nb_argument)){yyerror("Sementique erreur");}else {$$=0;nb_argument=0;}} // enspara parceque te9der t3ayat l fct b ay haja mouhim treja3 valeur 
    ;
ENSpara: ENSpara verg valeur {nb_argument++;} | valeur {nb_argument++;}
;
LOGI: mc_true
    | mc_false
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
var: idf {if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} 
     | idf po ENSpara pf {if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} 
;
if_statement: mc_if po CONDI pf mc_then ENSINST else_clause mc_endif 
;
else_clause: mc_else ENSINST |
;
assignment: OGassi aff valeur pvg //OGassi operande gauche d'afectation 
;
OGassi: idf{if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} 
    | idf po ENSpara pf {if(Declarer($1)){
        yyerror("Sementique erreur");      
    }} 
;
valeur: str { $$=0;}
        | EXPRE {$$=$1;} //valeur ay haja 3andha valeur true false 5 4 7 "dfsakl" max(5)
;
read_statement: mc_read po var pf pvg // kanet idf fi blaset var dertha ha ka parceque 9ader ydir read(t(5)); nafs echi f write var mechi idf
;
write_statement: mc_write po ENS_PARA_WRITE pf pvg 
;
ENS_PARA_WRITE: ENS_PARA_WRITE verg str  | ENS_PARA_WRITE verg var | str | var
;
dowhile_statement: mc_dowhile po CONDI pf ENSINST mc_enddo 
;
CONDI: CONDI mc_or CONDIT | CONDI mc_and CONDIT | CONDIT 
;
CONDIT: po CONDI pf | EXPLOGI 
;
EXPLOGI: EXPRE lt EXPRE | EXPRE gt EXPRE | EXPRE ge EXPRE | EXPRE eq EXPRE | EXPRE ne EXPRE | EXPRE le EXPRE 
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
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    
   return 0;
 }
 yywrap ()
 {}

int yyerror ( char*  msg )
 {
    printf("File \"%s\", line %d, character %d: %s\n",file_name, nb_ligne, Col,msg);
    exit(EXIT_FAILURE);
  }
