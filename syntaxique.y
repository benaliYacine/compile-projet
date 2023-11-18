%{
    int nb_ligne=1, Col=1;
%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token idf cst aff mc_prgrm mc_rtin inti real mc_endr mc_call mc_dim mc_logi mc_char mc_true mc_false mc_read mc_write pvg str mc_int mc_real mc_end mc_if mc_then mc_else mc_dowhile mc_enddo mc_equival mc_or ge eq ne le add sub mul divi mc_and mc_endif lt gt po pf verg err 
%%
s: FCT mc_prgrm idf DEC INST mc_end { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
FCT: FCT TYPE mc_rtin idf po ENSIDF pf DEC INST idf aff idf pvg mc_endr | TYPE mc_rtin idf po ENSIDF pf DEC INST idf aff idf pvg mc_endr
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
DEC: TYPE idf mc_dim po TAILLE pf pvg DEC | TYPE idf mul inti pvg DEC | TYPE ENSIDF pvg DEC | TYPE ENSIDF pvg | TYPE idf mul inti pvg | TYPE idf mc_dim po TAILLE pf pvg
;
TAILLE: TAILLE inti verg | inti
;
EXPRE: EXPRE add EXPRET | EXPRET  
;
EXPRET: EXPRET mul EXPREF | EXPREF
;
EXPREF: po EXPREF pf | EXPREI
;
EXPREI: idf | inti | real | LOGI | idf po TAILLE pf | mc_call idf po ENSIDF pf | str
;
LOGI: mc_true | mc_false
;
ENSIDF: ENSIDF idf verg | idf
;
INST: if_statement | assignment | read_statement | write_statement | dowhile_statement 
;
if_statement: mc_if po CONDI pf mc_then INST mc_endif 
;
assignment: idf aff EXPRE pvg 
;
read_statement: mc_read po idf pf pvg 
;
write_statement: mc_write po str verg ENSIDF pf pvg | mc_write po str pf pvg 
;
dowhile_statement: mc_dowhile po CONDI pf INST mc_enddo 
;
CONDI: CONDI mc_or CONDIT | CONDIT
;
CONDIT: po CONDIT pf | EXPLOGI
;
EXPLOGI: EXPRE lt EXPRE | EXPRE gt EXPRE | EXPRE aff aff EXPRE | EXPRE ge EXPRE | EXPRE eq EXPRE | EXPRE ne EXPRE | EXPRE le EXPRE
;
%%

int main ()
{
   initialisation();
   yyparse();
   afficher();
   return 0;
 }
 yywrap ()
 {}
 int yyerror ( char*  msg )
 {
    printf ("Erreur Syntaxique a ligne %d a colonne %d \n",nb_ligne,Col);
  }