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
s: ENSFCT PRGM_PRIN { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
PRGM_PRIN: mc_prgrm idf ENSDEC ENSINST mc_end
;
ENSFCT: FCT ENSFCT | FCT
;
FCT: TYPE mc_rtin idf po ENSIDF pf DEC ENSINST idf aff idf pvg mc_endr
;
TYPE: mc_int | mc_real | mc_char | mc_logi
;
ENSDEC: DEC ENSDEC | DEC
;
DEC: TYPE ENSIDF pvg | TYPE idf mul inti pvg | TYPE idf mc_dim po TAILLE pf pvg
;
TAILLE: verg inti TAILLE | inti
;
EXPRE: EXPRET add EXPRE | EXPRET sub EXPRE | EXPRET  
;
EXPRET: EXPREF mul EXPRET | EXPREF divi EXPRET | EXPREF
;
EXPREF: po EXPRE pf | EXPREI
;
EXPREI: idf | inti | real | LOGI | idf po TAILLE pf | mc_call idf po ENSIDF pf | str
;
LOGI: mc_true | mc_false
;
ENSIDF: idf verg ENSIDF | idf
;
ENSINST: INST ENSINST | INST
;
INST: if_statement | read_statement | write_statement | dowhile_statement
;
if_statement: mc_if po CONDI pf mc_then ENSINST else_clause mc_endif
;
else_clause: mc_else ENSINST |
;
//assignment: idf aff EXPRE pvg ;
read_statement: mc_read po idf pf pvg 
;
write_statement: mc_write po str verg ENSIDF pf pvg | mc_write po str pf pvg 
;
dowhile_statement: mc_dowhile po CONDI pf ENSINST mc_enddo 
;
CONDI: CONDIT mc_or CONDI | CONDIT mc_and CONDI | CONDIT
;
CONDIT: po CONDI pf | EXPLOGI
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