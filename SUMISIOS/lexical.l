%{

#include <stdlib.h> // For atoi and atof
#include <limits.h> // For INT_MAX and INT_MIN

#include <string.h>
char* file_name;
int nb_ligne=1;
int Col=1;

char *pointPtr; //point pointer
%}

lettre [a-zA-Z]
commentaire %.*;
chiffre [0-9]
idf {lettre}({lettre}|{chiffre})*
str \".*\"
int -{chiffre}+|{chiffre}+
real (-{chiffre}+|{chiffre}+)\.{chiffre}+

%%

{commentaire}
 /*comentaire commence par % et termine par;*/

"PROGRAM" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"ROUTINE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"ENDR" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"CALL" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"DIMENSION" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"LOGICAL" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"CHARACTER" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"TRUE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"FALSE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"READ" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"WRITE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}

"INTEGER" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"REAL" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"END" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"IF" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"THEN" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"ELSE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"ENDIF" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"DOWHILE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"ENDDO" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"EQUIVALENCE" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"OR" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}
"AND" { printf (" L entite lexicale reconnue est %s \n", yytext);Col= Col + strlen(yytext);}

".LT." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
".GT." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
".LE." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
".NE." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
".EQ." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
".GE." {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}


{idf} { 
              Col= Col + strlen(yytext);
			  if (strlen(yytext)>10) printf ("warning: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, Col);
              printf (" L entite lexicale reconnue est %s \n", yytext); }

{int} {
			  if (atof(yytext)<-32768 || atof(yytext)>32767){
				printf("File \"%s\", line %d, character %d: lexical error\n",file_name, nb_ligne, Col);}
				//puisqu'on a consiere la detection des entiers trop long comme erreur: si on veut arrêter l'analyseur lexical lorsqu'il trouve une erreur on peut ajouter  yyterminate()
				//si on consiere la detection des entiers trop long comme warning: printf("warning: Entité entiere trop long a ligne %d a la colonne %d \n ",nb_ligne, Col);
    			Col= Col + strlen(yytext); 
			  printf (" L entite lexicale reconnue est %s \n", yytext);
			  }
{real} {
			double var=(double)atof(yytext);
			  if (var > (double)INT_MAX || var < (double)INT_MIN){ // bach 9bel ma dir (int) tvirifi ida numero sghir 3la int max w kbir 3la int min pareceque koun la rah yesra mouchkil fi (int) tedkhol f boucle infini w (double) 9ader ma tzidhach parceque l compilateur wahdou ki yel9ak m compari int m3a double yhawal l int l double mais koun tzidha nta khir (good practice)
			  		printf("File \"%s\", line %d, character %d: lexical error\n",file_name, nb_ligne, Col);
 			  } else {

					/*--------------int part-----------------*/
					int intPart = (int)var;

					/*--------------fractional part-----------------*/
					pointPtr = strchr(yytext, '.');// strchr tchouf fel str yytext win jay l pointer ta3 el '.' w t7oto f pointPtr
					double fractionalPart = atof(pointPtr + 1); // atof Convert fractional part to double (double-precision floating-point(floating-point maydirch mouchkil hna houwa yrod l vergule be ta9rib hna khlas ne7tajou ghi l int part)),kout dayer atoi (Convert fractional part to int) mais atof khir bach ida kan chifre li mor l vergule maye9derch yji f int afoi dirlek problem mais atof y7awlou l double 3adi tani atoi mafihach erreur handeling( It doesn't handle floating-point numbers-There's no error handling for overflows or underflows.)
					if (intPart<-32768 || intPart>32767 || (int)fractionalPart>32767){
						printf("File \"%s\", line %d, character %d: lexical error\n",file_name, nb_ligne, Col);}
			  }
			  Col= Col + strlen(yytext); 
			  printf (" L entite lexicale reconnue est %s \n", yytext);
			  }

"/" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"*" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"-" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"+" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"=" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
";" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"(" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
")" {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}
"," {printf (" L entite lexicale reconnue est %s \n", yytext); Col= Col + strlen(yytext);}

{str} { 
              Col= Col + strlen(yytext);
              printf (" L entite lexicale reconnue est %s \n", yytext); }

[ \t] Col= Col + strlen(yytext);
\n {Col= 1; nb_ligne++;}

. { printf("File \"%s\", line %d, character %d: lexical error\n",file_name, nb_ligne, Col);Col= Col + strlen(yytext);}

%%

int main(int argc, char** argv){
 	if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            // Handle error
            return 1;
        }
        yyin = file;
    }
    yylex();

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}



/*9bel mandir yyin
int main(){
yylex();
return 0;
}
*/
