%{
    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include <stdlib.h>
    extern FILE *yyin;
%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token idf aff mc_prgrm mc_rtin inti real mc_endr mc_call mc_dim mc_logi mc_char mc_true mc_false mc_read mc_write pvg str mc_int mc_real mc_end mc_if mc_then mc_else mc_dowhile mc_enddo mc_equival mc_or ge eq ne le add sub mul divi mc_and mc_endif lt gt po pf verg err 
%left add sub
%left mul divi
%left mc_or mc_and
%%
s: FCTS PRGM_PRIN { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
PRGM_PRIN: mc_prgrm idf DECS INSTS mc_end
;
FCTS: VIDE | ENSFCT
;
VIDE:
;
ENSFCT: ENSFCT FCT | FCT
;
FCT: TYPE mc_rtin idf po ENSIDF pf DECS ENSINST assignment mc_endr | TYPE mc_rtin idf po ENSIDF pf DECS assignment mc_endr
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
DECS: VIDE | ENSDEC
;
ENSDEC: ENSDEC DEC | DEC
;
DEC: TYPE ENSIDF pvg | TYPE idf mul inti pvg | TYPE idf mc_dim po TAILLE pf pvg
;
TAILLE: TAILLE verg inti | inti
;
EXPRE
    : EXPRE add TERM
    | EXPRE sub TERM
    | TERM
    ;

TERM
    : TERM mul FACTOR
    | TERM divi FACTOR
    | FACTOR
    ;

FACTOR
    : po EXPRE pf
    | OPERAND
    ;

OPERAND
    : idf
    |inti
    | real
    | idf po TAILLE pf
    | mc_call idf po ENSpara pf
    ;
ENSpara: ENSpara verg valeur | valeur
;
LOGI: mc_true | mc_false
;
ENSIDF: ENSIDF verg idf | idf
;
INSTS: VIDE | ENSINST
;
ENSINST: ENSINST INST | INST
;
INST: if_statement | read_statement | write_statement | dowhile_statement | assignment
;
if_statement: mc_if po CONDI pf mc_then ENSINST else_clause mc_endif 
;
else_clause: mc_else ENSINST |
;
assignment: OGassi aff valeur pvg //OGassi operande gauche d'afectation 
;
OGassi: idf | idf po TAILLE pf
;
valeur: LOGI | str | EXPRE //valeur ay haja 3andha valeur true false 5 4 7 "dfsakl" max(5)
;
read_statement: mc_read po idf pf pvg 
;
write_statement: mc_write po ENS_PARA_WRITE pf pvg 
;
ENS_PARA_WRITE: ENS_PARA_WRITE verg str  | ENS_PARA_WRITE verg idf | str | idf
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
    printf("File \"%s\", line %d, character %d: syntaxique error\n",file_name, nb_ligne, Col);
  }