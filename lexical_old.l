%{
extern nb_ligne; // extern bach te9der testa3amlou dans plusieurs fichiers
extern Col;
#include "syntaxique_old.tab.h"
#include <stdbool.h>
 #include <stdlib.h> // For atoi and atof
 #include <limits.h> // For INT_MAX and INT_MIN
 #include <string.h>
 extern YYSTYPE yylval; //pach te9der tpartager les vals m3a syntaxique fel syxt tzid el union w lazem fel token tzid el type w fel gramaire tweli te9der tdir $1 $2
 extern file_name;
 char *pointPtr; //point pointer
int P_OU_F=0;//is pares nom programme ou fonction
float valeur;
 char type[20]=" ";
%}

lettre [a-zA-Z]
commentaire %.*\n 
chiffre [0-9]
idf {lettre}({lettre}|{chiffre})*
str \"[^"]*\"
int -{chiffre}+|{chiffre}+
real (-{chiffre}+|{chiffre}+)\.{chiffre}+
%%

{commentaire} {nb_ligne++; Col=1;}


"PROGRAM" {strcpy(type," ");rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);P_OU_F=1;return mc_prgrm;}
"ROUTINE" {strcat(type," FONCTION");rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);P_OU_F=1;return mc_rtin;}
"ENDR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_endr;}
"CALL" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_call;}
"DIMENSION" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_dim;}
"LOGICAL" {strcpy(type,yytext);rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_logi;}
"CHARACTER" {strcpy(type,yytext);rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_char;}
"TRUE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_true;}
"FALSE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_false;}
"READ" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_read;}
"WRITE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_write;}

"INTEGER" {strcpy(type,yytext);rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_int;}
"REAL" {strcpy(type,yytext);rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_real;}
"END" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_end;}
"IF" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_if;}
"THEN" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_then;}
"ELSE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_else;}
"ENDIF" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_endif;}
"DOWHILE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_dowhile;}
"ENDDO" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_enddo;}
"EQUIVALENCE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_equival;}
"FOR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_for;}


".OR." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_or;}
".AND." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_and;}
".LT." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return lt;}
".GT." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return gt;}
".LE." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return le;}
".NE." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return ne;}
".EQ." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return eq;}
".GE." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return ge;}



{idf} {yylval.str=strdup(yytext);
					rechercher(yytext,"IDF",type," ",0," ",P_OU_F); 
					if(P_OU_F==1){
						P_OU_F=0;
						strcpy(type,"ARGUMENT");
					}
					 
              Col= Col + strlen(yytext);
			  if (yyleng>10) printf ("warning: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, Col);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  return idf;
			  }

{int} {yylval.entier=atoi(yytext);
			  if (atof(yytext)<-32768 || atof(yytext)>32767){
				yyerror("Lexical error",yytext,"est trop long.");return err;}
				//puisqu'on a consiere la detection des entiers trop long comme erreur: si on veut arrêter l'analyseur lexical lorsqu'il trouve une erreur on peut ajouter  yyterminate()
				//si on consiere la detection des entiers trop long comme warning: printf("warning: Entité entiere trop long a ligne %d a la colonne %d \n ",nb_ligne, Col);
			  printf (" L entite lexicale reconnue est %s \n", yytext);
              //valeur=(float)atof(yytext);
			  rechercher(yytext,"Cst","INTEGER",yytext,0," ",P_OU_F);

			  Col= Col + strlen(yytext);

			  //printf (" L entite lexicale reconnue est %s \n", yytext);
			  return inti;}
{real} {
			  double var=(double)atof(yytext);
			  if (var > (double)INT_MAX || var < (double)INT_MIN){// bach 9bel ma dir (int) tvirifi ida numero sghir 3la int max w kbir 3la int min pareceque koun la rah yesra mouchkil fi (int) tedkhol f boucle infini w (double) 9ader ma tzidhach parceque l compilateur wahdou ki yel9ak m compari int m3a double yhawal l int l double mais koun tzidha nta khir (good practice)
			  		yyerror("Lexical error",yytext,"est trop long.");return err;
 			  } else {
					yylval.reel=atof(yytext);
					/*--------------int part-----------------*/
					int intPart = (int)var;

					/*--------------fractional part-----------------*/
					pointPtr = strchr(yytext, '.');// strchr tchouf fel str yytext win jay l pointer ta3 el '.' w t7oto f pointPtr
					double fractionalPart = atof(pointPtr + 1); // atof Convert fractional part to double (double-precision floating-point(floating-point maydirch mouchkil hna houwa yrod l vergule be ta9rib hna khlas ne7tajou ghi l int part)),kout dayer atoi (Convert fractional part to int) mais atof khir bach ida kan chifre li mor l vergule maye9derch yji f int afoi dirlek problem mais atof y7awlou l double 3adi tani atoi mafihach erreur handeling( It doesn't handle floating-point numbers-There's no error handling for overflows or underflows.)  
					if (intPart<-32768 || intPart>32767 || (int)fractionalPart>32767){
						yyerror("Lexical error",yytext,"est trop long.");return err;}
			  }
              rechercher(yytext,"Cst","REAL",yytext,0," ",P_OU_F); 
			  Col= Col + strlen(yytext); 
			  printf (" L entite lexicale reconnue est %s \n", yytext);
			  return real;}
{str} {yylval.str=strdup(yytext);
			  rechercher(yytext,"Cst","CHARACTER",yytext,0," ",P_OU_F);  
              Col= Col + strlen(yytext);
              printf (" L entite lexicale reconnue est %s \n", yytext); 
			  return str;}

"/" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return divi;}
"*" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mul;}
"-" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return sub;}
"+" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return add;}
"=" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return aff;}
";" {strcpy(type," ");rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return pvg;}
"(" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return po;}
")" {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return pf;}
"," {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return verg;}


[ \t] Col= Col + strlen(yytext);
\n {Col= 1; nb_ligne++;strcpy(type," ");}

. {yyerror("Lexical error",yytext,"est non accaptee.");return err;} 
%%