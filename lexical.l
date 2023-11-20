%{
extern nb_ligne;
extern Col;
#include "Syntaxique.tab.h"
 #include "ts.h"
 extern YYSTYPE yylval;
%}

lettre [a-zA-Z]
commentaire %({lettre}|{chiffre})*\n
chiffre [0-9]
idf {lettre}({lettre}|{chiffre})*
str \".*\"
int -{chiffre}+|{chiffre}+
real (-{chiffre}+|{chiffre}+)\.{chiffre}+

%%

{commentaire} {Col= 1; nb_ligne++;}


"PROGRAM" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_prgrm;}
"ROUTINE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_rtin;}
"ENDR" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_endr;}
"CALL" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_call;}
"DIMENSION" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_dim;}
"LOGICAL" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_logi;}
"CHARACTER" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_char;}
"TRUE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_true;}
"FALSE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_false;}
"READ" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_read;}
"WRITE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_write;}

"INTEGER" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_int;}
"REAL" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_real;}
"END" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_end;}
"IF" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_if;}
"THEN" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_then;}
"ELSE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_else;}
"ENDIF" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_endif;}
"DOWHILE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_dowhile;}
"ENDDO" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_enddo;}
"EQUIVALENCE" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_equival;}
"OR" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_or;}
"AND" {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_and;}

".LT." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return lt;}
".GT." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return gt;}
".LE." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return le;}
".NE." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return ne;}
".EQ." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return eq;}
".GE." {rechercher(yytext,"Mot cle",0,0,2); Col= Col + strlen(yytext);return ge;}



{idf} {yylval.str=strdup(yytext);
			  rechercher(yytext,"IDF"," ",0,0);  
              Col= Col + strlen(yytext);
			  if (yyleng>10) printf ("warning: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, Col);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  return idf;}

{int} {yylval.entier=atoi(yytext);
			  if (atof(yytext)<-32768 || atof(yytext)>32767){
				printf ("ereur: Entité entiere trop long a ligne %d a la colonne %d \n", nb_ligne, Col);return err;}
              rechercher(yytext,"Cst entiere","INTEGER",atof(yytext),0); 
			  Col= Col + strlen(yytext); 
			  printf (" L entite lexicale reconnue est %s \n", yytext);
			  return inti;}
{real} {yylval.entier=atoi(yytext);
			  int intPart = (int)atof(yytext);
			  float fractionalPart = atof(yytext) - intPart;
			  // Handling negative numbers
				if (fractionalPart < 0) {
					fractionalPart = -fractionalPart;
				}

				// Remove the fractional part by multiplying by 10 until it's gone
				int fractionalPartAsInt = 0;
				while (fractionalPart > 0) {
					fractionalPart *= 10;
					int digit = (int)fractionalPart;
					fractionalPartAsInt = fractionalPartAsInt * 10 + digit;
					fractionalPart -= digit;
				}
			  if (intPart<-32768 || intPart>32767 || fractionalPartAsInt>32768){
				printf ("ereur: Entité real trop long a ligne %d a la colonne %d \n", nb_ligne, Col);return err;}
              
              rechercher(yytext,"Cst real","FLOAT",atof(yytext),0); 
			  Col= Col + strlen(yytext); 
			  printf (" L entite lexicale reconnue est %s \n", yytext);
			  return real;}

"/" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return divi;}
"*" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return mul;}
"-" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return sub;}
"+" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return add;}
"=" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return aff;}
";" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return pvg;}
"(" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return po;}
")" {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return pf;}
"," {rechercher(yytext,"separateur",0,0,2); Col= Col + strlen(yytext);return verg;}

{str} {yylval.str=strdup(yytext);
			  rechercher(yytext,"IDF"," ",0,0);  
              Col= Col + strlen(yytext);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  return str;}

[ \t] Col= Col + strlen(yytext);
\n {Col= 1; nb_ligne++;}

. {printf("Entité lexicale non reconnue a ligne %d a la colonne %d \n", nb_ligne, Col);return err;}
%%