#ifndef pgm_H
#define pgm_H

typedef struct
{
    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];
} qdr;

qdr quad[1000];
extern int qc;

void quadr(char opr[], char op1[], char op2[], char res[]);

void ajour_quad(int num_quad, int colon_quad, char val[]);
void createQuadTabDec(char *taille, char *tab);

void afficher_qdr();

#endif // pgm_H

