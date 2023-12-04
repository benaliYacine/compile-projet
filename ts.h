#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element *Lelement;
typedef struct element
{
   int state;
   char name[20];
   char code[20];
   char type[20];
   float val;
   Lelement svt;
 } element;

typedef struct elt *Lelt;
typedef struct elt
{ 
   char name[20];
   char type[20];
   Lelt svt;
} elt;
    Lelement tab=NULL,tete=NULL,prd=NULL;
    Lelt tabm=NULL,tabs=NULL,tetem=NULL,tetes=NULL,prdm=NULL,prds=NULL;
void inserer (char entite[], char code[],char type[],float val, int y)
{
    
  switch (y)
 { 
    
   case 0:/*insertion dans la table des IDF et CONST*/
      tab=malloc(sizeof(element));
       
       strcpy(tab->name,entite);
       strcpy(tab->code,code);
	   strcpy(tab->type,type);
	   tab->val=val;
       tab->svt=NULL;
       if(tete==NULL){
            tete=tab;
            prd=tete;
       }
            else {
                prd->svt=tab;
                prd=prd->svt;
            }
	   break;

   case 1:/*insertion dans la table des mots clÃ©s*/
   tabm=malloc(sizeof(elt));
       
       strcpy(tabm->name,entite);
       strcpy(tabm->type,code);
       tabm->svt=NULL;
       if(tetem==NULL){
            tetem=tabm;
            prdm=tetem;
       }
            else {
                prdm->svt=tabm;
                prdm=prdm->svt;
            }
       break; 
    
   case 2:/*insertion dans la table des separateurs*/
    tabs=malloc(sizeof(elt));
      
      strcpy(tabs->name,entite);
      strcpy(tabs->type,code);
      tabs->svt=NULL;
       if(tetes==NULL){
            tetes=tabs;
            prds=tetes;
       }
            else {
                prds->svt=tabs;
                prds=prds->svt;
            }
      break;
 }

}

void rechercher (char entite[], char code[],char type[],float val,int y)	
{

int j,i;
tab=tete;
tabm=tetem;
tabs=tetes;
switch(y) 
  {
   case 0:/*verifier si la case dans la tables des IDF et CONST est libre*/
        //for (i=0;((i<1000)&&(tab->state==1))&&(strcmp(entite,tab->name)!=0);i++); 
        while(tab!=NULL&&strcmp(entite,tab->name)!=0){
            tab=tab->svt;
        }
        if(tab==NULL)
        { 
	        
			inserer(entite,code,type,val,0); 
	      
         }
        else
          printf("entite existe deja\n");
        break;

   case 1:/*verifier si la case dans la tables des mots clÃ©s est libre*/
       
       while(tabm!=NULL&&strcmp(entite,tabm->name)!=0){
            tabm=tabm->svt;
        }
        if(tabm==NULL)
          inserer(entite,code,type,val,1);
        else
          printf("entite existe deja\n");
        break; 
    
   case 2:/*verifier si la case dans la tables des sÃ©parateurs est libre*/
          while(tabs!=NULL&&strcmp(entite,tabs->name)!=0){
            tabs=tabs->svt;
        }
        if(tabs==NULL)
         inserer(entite,code,type,val,2);
        else
   	       printf("entite existe deja\n");
        break;

  }

}

void afficher()
{
tab=tete;
tabm=tetem;
tabs=tetes;

printf("/***************Table des symboles IDF*************/\n");
printf("____________________________________________________________________\n");
printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite\n");
printf("____________________________________________________________________\n");
  
while(tab!=NULL)
{	
        printf("\t|%10s |%15s | %12s | %12f\n",tab->name,tab->code,tab->type,tab->val);
         
      
    tab=tab->svt;
}

 
printf("\n/***************Table des symboles mots clÃ©s*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
  
while(tabm!=NULL){
        printf("\t|%10s |%12s | \n",tabm->name, tabm->type);
               
      
      tabm=tabm->svt;
}

printf("\n/***************Table des symboles sÃ©parateurs*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
  
while(tabs!=NULL){
        printf("\t|%10s |%12s | \n",tabs->name,tabs->type );
        
      
      tabs=tabs->svt;
}

}
