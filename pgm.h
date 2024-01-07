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

char* IntToSTR(int i);

char* FloatToSTR(int i);

void quadr(char opr[], char op1[], char op2[], char res[]);

void createQuadCompare(int type, char *cond1, char *cond2, char *res);

void createQuadLogic(int type, char *cond1, char *cond2, char *res);

void ajour_quad(int num_quad, int colon_quad, char val[]);

void afficher_qdr();

#endif // pgm_H
