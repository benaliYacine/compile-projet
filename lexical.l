%{
extern nb_ligne; 
extern Col;
#include "Syntaxique.tab.h"
#include <stdbool.h>
#include <stdlib.h> 
#include <limits.h> 
#include <string.h>
extern YYSTYPE yylval; 
extern file_name;
char *pointPtr; 
int P_OU_F=0; 
float valeur;
char type[20]=" ";
%}

lettre [a-zA-Z]
maj [A-Z]
chiffre [0-9]
idf {maj}({lettre}|{chiffre})*
str \"[^"]*\"
int (-{chiffre}+|{chiffre}+)
float (-{chiffre}+|{chiffre}+)\.{chiffre}+
char \'[^']\'
commentaire §.*\n

%%

{commentaire} {nb_ligne++; Col=1;}

"DATA" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_data;}
"END" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_end;}
"CODE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_code;}
"INTEGER" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_integer;}
"FLOAT" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_float;}
"CHAR" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_char;}
"STRING" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_string;}
"CONST" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_const;}
"VECTOR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_vector;}
"READ" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_read;}
"DISPLAY" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_display;}
"IF" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_if;}
"ELSE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_else;}
"FOR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_for;}
"NOT" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_not;}
"TRUE" {
    yylval.str = strdup("true");
    rechercher(yytext, "Cst", "LOGICAL", "true", 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return mc_true;
}
"FALSE" {
    yylval.str = strdup("false");
    rechercher(yytext, "Cst", "LOGICAL", "false", 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return mc_false;
}

".AND." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_and;}
".OR." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_or;}
".G." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_g;}
".L." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_l;}
".GE." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_ge;}
".LE." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_le;}
".EQ." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_eq;}
".DI." {rechercher(yytext,"separateur"," "," ", 2," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_di;}

{idf} {
    yylval.str = strdup(yytext);
    rechercher(yytext,"IDF",type," ",0," ",P_OU_F); 
    if(P_OU_F==1){
        P_OU_F=0;
        strcpy(type,"ARGUMENT");
    }
    Col += strlen(yytext);
    if (yyleng > 8) {
        printf ("warning: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, Col);
        
    }
    printf("L'entite lexicale reconnue est %s\n", yytext); 
    return idf;
}

{int} {
    yylval.entier = atoi(yytext);
    if (atof(yytext) < -32768 || atof(yytext) > 32767) {
        yyerror("Lexical error", yytext, "est trop long.");
        
    }
    rechercher(yytext, "Cst", "INTEGER", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return inti;
}

{float} {
    double var = (double)atof(yytext);
    if (var > (double)INT_MAX || var < (double)INT_MIN) {
        yyerror("Lexical error", yytext, "est trop long.");
        
    } else {
        yylval.reel = atof(yytext);
        
        
        int intPart = (int)var;
        
        pointPtr = strchr(yytext, '.'); 
        double fractionalPart = atof(pointPtr + 1);
        
        if (intPart < -32768 || intPart > 32767 || (int)fractionalPart > 32767) {
            yyerror("Lexical error", yytext, "est trop long.");
            
        }
    }
    rechercher(yytext, "Cst", "FLOAT", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return real;
}

{char} {
    yylval.str = strdup(yytext);
    rechercher(yytext, "Cst", "CHAR", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return ch;
}

{str} {
    yylval.str = strdup(yytext);
    rechercher(yytext, "Cst", "STRING", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return str;
}

"+" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return plus;}
"-" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return minus;}
"*" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mul;}
"/" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return divi;}
"=" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return eq;}
";" {strcpy(type, " "); rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return pvg;}
":" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return deux_points;}
"[" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return crochet_ouv;}
"]" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return crochet_ferm;}
"(" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return par_ouv;}
")" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return par_ferm;}
"," {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return virgule;}
"|" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return barre;}
"@" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return arobase;}

[ \t] {Col += strlen(yytext);}

\n {Col= 1; nb_ligne++; strcpy(type," ");}

. {yyerror("Lexical error", yytext, "est non acceptee."); }

%%