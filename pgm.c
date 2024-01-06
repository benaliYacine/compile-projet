#include "pgm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//convert interger to string
char* IntToSTR(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}

char* FloatToSTR(int i){
	char s[15];
	sprintf(s,"%g",i);
	return strdup(s);
}


//creation d'1 quad arithmeitque
void createQuadCompare(int type, char *cond1, char *cond2, char *res){
	char *TypeBR;
	switch(type){
		case 1 :{//1==> "==" (égale)
			TypeBR=strdup("BNE");
		}
		break;
		case 2 :{//2==> "!=" (different)
			TypeBR=strdup("BE");
		}
		break;
		case 3 :{//3==> ">=" higher Or Equal
			TypeBR=strdup("BL");
		}
		break;
		case 4 :{//4==> "<=" lower Or Equal
			TypeBR=strdup("BG");
		}
		break;
		case 5 :{//5==> "<" lower
			TypeBR=strdup("BGE");
		}
		break;
		case 6 :{//6==> ">" higher
			TypeBR=strdup("BLE");
		}
		break;
	}
	quadr(TypeBR,IntToSTR(qc+3),cond1,cond2);
	quadr("=","1","vide",res);
	quadr("BR",IntToSTR(qc+2),"vide","vide");
	quadr("=","0","vide",res);
}


//creation d'1 quad logique
void createQuadLogic(int type, char *cond1, char *cond2, char *res){
	switch(type){
		case 1 :{//1==> not
			quadr("BNZ",IntToSTR(qc+3),cond1,"vide");
			quadr("=","1","vide"   ,res);
			quadr("BR",IntToSTR(qc+2),"vide","vide");
			quadr("=","0","vide",res);
		}
		break;
		case 2 :{//2==> or
			quadr("BNZ",IntToSTR(qc+4),cond1,"vide");
			quadr("BNZ",IntToSTR(qc+3),cond2,"vide");
			quadr("=","0","vide",res);
			quadr("BR",IntToSTR(qc+2),"vide","vide");
			quadr("=","1","vide",res);
		}
		break;
		case 3 :{//3==> and
			quadr("BZ",IntToSTR(qc+4),cond1,"vide");
			quadr("BZ",IntToSTR(qc+3),cond2,"vide");
			quadr("=","1","vide",res);
			quadr("BR",IntToSTR(qc+2),"vide","vide");
			quadr("=","0","vide",res);
		}
		break;
	}
}  


void quadr(char opr[], char op1[], char op2[], char res[])
{
    strcpy(quad[qc].oper, opr);
    strcpy(quad[qc].op1, op1);
    strcpy(quad[qc].op2, op2);
    strcpy(quad[qc].res, res);
    qc++;
}

void ajour_quad(int num_quad, int colon_quad, char val[])
{
    if (colon_quad == 0)
        strcpy(quad[num_quad].oper, val);
    else if (colon_quad == 1)
        strcpy(quad[num_quad].op1, val);
    else if (colon_quad == 2)
        strcpy(quad[num_quad].op2, val);
    else if (colon_quad == 3)
        strcpy(quad[num_quad].res, val);
}

void afficher_qdr()
{
    printf("*********************LesQuadruplets***********************\n");
    int i;
    for (i = 0; i < qc; i++)
    {
        printf("\n %d - ( %s , %s , %s , %s )", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
        printf("\n---------------------------------------------------\n");
    }
}
