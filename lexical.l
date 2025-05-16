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
int P_OU_F=1; 
float valeur;
char type[20]=" ";
%}

lettre [a-zA-Z]
commentaire §.*\n
maj [A-Z]
chiffre [0-9]
idf {maj}({lettre}|{chiffre})*
str \"[^"]*\"
int {chiffre}+|\([\+\-]{chiffre}+\)
float {chiffre}+\.{chiffre}+|\([\+\-]{chiffre}+\.{chiffre}+\)
character \'[^']\'

%%

{commentaire} {nb_ligne++; Col=1;}

"DATA" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_data;}
"END" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_end;}
"CODE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_code;}
"INTEGER" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_integer;}
"FLOAT" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_float;}
"CHAR" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_char;}
"STRING" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_string;}
"CONST" { strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_const;}
"LOGICAL" {strcpy(type,yytext); rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_logi;}
"VECTOR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_vector;}
"READ" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_read;}
"DISPLAY" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_display;}
"IF" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_if;}
"ELSE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_else;}
"FOR" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mc_for;}
"DOWHILE" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_dowhile;}
"ENDDO" {rechercher(yytext,"Mot cle"," "," ", 1," ",P_OU_F); Col= Col + strlen(yytext); printf (" L entite lexicale reconnue est %s \n", yytext);return mc_enddo;}
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
    char* text_to_convert = yytext;
    char* allocated_text = NULL; // Will hold dynamically allocated string if needed

    if (yytext[0] == '(' && yytext[yyleng-1] == ')') {
        size_t len = yyleng - 2;
        allocated_text = (char*)malloc(len + 1); // +1 for null terminator
        if (allocated_text) {
            strncpy(allocated_text, yytext + 1, len);
            allocated_text[len] = '\0';
            text_to_convert = allocated_text;
        } else {
            // Optional: Handle memory allocation failure, e.g., by calling yyerror
            // For now, text_to_convert will remain yytext, which might lead to atof errors later
            // but avoids a crash here. A more robust handling would be:
            yyerror("Lexical error", yytext, "memory allocation failed for float processing");
            // Potentially return an error token or exit, depending on desired lexer behavior
        }
    }

    double var = (double)atof(text_to_convert);
    if (var > (double)INT_MAX || var < (double)INT_MIN) {
        yyerror("Lexical error", yytext, "est trop long.");
    } else {
        yylval.reel = atof(text_to_convert);
        
        
        int intPart = (int)var;
        
        pointPtr = strchr(text_to_convert, '.'); 
        double fractionalPart = 0.0;
        if (pointPtr != NULL) {
            fractionalPart = atof(pointPtr + 1);
        }
        
        if (intPart < -32768 || intPart > 32767 || (int)fractionalPart > 32767) {
            yyerror("Lexical error", yytext, "est trop long.");
            
        }
    }
    // Pass the original yytext for lexeme and text_to_convert for value if they differ
    rechercher(yytext, "Cst", "FLOAT", text_to_convert, 0, " ", P_OU_F); 
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    
    if (allocated_text != NULL) { // Free the duplicated string if it was created
        free(allocated_text);
    }
    return real;
}

{character} {
    yylval.str = strdup(yytext);
    rechercher(yytext, "Cst", "CHAR", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return character;
}

{str} {
    yylval.str = strdup(yytext);
    rechercher(yytext, "Cst", "STRING", yytext, 0, " ", P_OU_F);
    Col += strlen(yytext);
    printf("L'entite lexicale reconnue est %s\n", yytext);
    return str;
}

"+" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return add;}
"-" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return sub;}
"*" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return mul;}
"/" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return divi;}
"=" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return aff;}
";" {strcpy(type, " "); rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return pvg;}
":" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return deux_points;}
"[" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return crochet_ouv;}
"]" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return crochet_ferm;}
"(" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return po;}
")" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return pf;}
"," {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return verg;}
"|" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return barre;}
"@" {rechercher(yytext, "separateur", " ", " ", 2, " ", P_OU_F); Col += strlen(yytext); printf("L'entite lexicale reconnue est %s\n", yytext); return arobase;}

[ \t] {Col += strlen(yytext);}

\n {Col= 1; nb_ligne++; strcpy(type," ");}

. {yyerror("Lexical error", yytext, "est non acceptee."); }


%%