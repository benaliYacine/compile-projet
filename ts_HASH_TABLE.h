#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element_type1 *pointer_element1;
typedef struct element_type1
{
  char name[20];
  char code[20];
  char type[20];
  float val;
  char taille[20];
  pointer_element1 svt;
} element_type1;

typedef struct element_type2 *pointer_element2;
typedef struct element_type2
{
  char name[20];
  char type[20];
  pointer_element2 svt;
} element_type2;

pointer_element1 tab_hachage[300]; // idf const
pointer_element2 tab_hachage_m[300], tab_hachage_s[300];
pointer_element1 tab = NULL, prd = NULL;
pointer_element2 tabm = NULL, tabs = NULL, prdm = NULL, prds = NULL;
void initialisation()
{
  int i;
  for (i = 0; i < 300; i++)
  {
    tab_hachage[i] = NULL;
    tab_hachage_s[i] = NULL;
    tab_hachage_m[i] = NULL;
  }
}
int fonction_de_hachage(char name[20])
{
  return ((int)name[0] + (int)name[1]) % 300;
}
void inserer(char entite[], char code[], char type[], float val, int y, int f, char taille[])
{
  switch (y)
  {

  case 0: /*insertion dans la table des IDF et CONST*/
    tab = malloc(sizeof(element_type1));
    if (tab == NULL)
      printf("memoire plein\n");
    else
    {
      strcpy(tab->name, entite);
      strcpy(tab->code, code);
      strcpy(tab->type, type);
      tab->val = val;
      strcpy(tab->taille, taille);
      tab->svt = NULL;
      if (tab_hachage[f] == NULL)
      {
        tab_hachage[f] = tab;
      }
      else
      {
        prd = tab_hachage[f];
        while (prd->svt != NULL)
          prd = prd->svt;
        prd->svt = tab;
      }
    }
    break;

  case 1: /*insertion dans la table des mots clÃ©s*/
    tabm = malloc(sizeof(element_type2));
    if (tabm == NULL)
      printf("memoire plein\n");
    else
    {
      strcpy(tabm->name, entite);
      strcpy(tabm->type, code);
      tabm->svt = NULL;
      if (tab_hachage_m[f] == NULL)
      {
        tab_hachage_m[f] = tabm;
      }
      else
      {
        prdm = tab_hachage_m[f];
        while (prdm->svt != NULL)
          prdm = prdm->svt;
        prdm->svt = tabm;
      }
    }
    break;

  case 2: /*insertion dans la table des separateurs*/
    tabs = malloc(sizeof(element_type2));

    if (tabs == NULL)
      printf("memoire plein\n");
    else
    {
      strcpy(tabs->name, entite);
      strcpy(tabs->type, code);
      tabs->svt = NULL;
      if (tab_hachage_s[f] == NULL)
      {
        tab_hachage_s[f] = tabs;
      }
      else
      {
        prdm = tab_hachage_s[f];
        while (prds->svt != NULL)
          prds = prds->svt;
        prds->svt = tabs;
      }
      break;
    }
  }
}

void rechercher(char entite[], char code[], char type[], float val, int y, char taille[])
{

  int f = fonction_de_hachage(entite);

  switch (y)
  {
  case 0: /*verifier si la case dans la tables des IDF et CONST est libre*/
    tab = tab_hachage[f];
    while (tab != NULL && strcmp(entite, tab->name) != 0)
    {
      tab = tab->svt;
    }
    if (tab == NULL)
    {
      inserer(entite, code, type, val, 0, f, taille);
    }
    else
    {
      if (strcmp(type, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab->type, type);

      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
      if (strcmp(taille, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab->taille, taille);
      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
      if (tab->val == 0.0)
      {
        // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        tab->val = val;
      }
      printf("entite existe deja\n");
    }
    break;

  case 1: /*verifier si la case dans la tables des mots clÃ©s est libre*/
    tabm = tab_hachage_m[f];

    while (tabm != NULL && strcmp(entite, tabm->name) != 0)
    {
      tabm = tabm->svt;
    }
    if (tabm == NULL)
      inserer(entite, code, type, val, 1, f, taille);
    else
      printf("entite existe deja\n");
    break;

  case 2: /*verifier si la case dans la tables des sÃ©parateurs est libre*/
    tabs = tab_hachage_s[f];

    while (tabs != NULL && strcmp(entite, tabs->name) != 0)
    {
      tabs = tabs->svt;
    }
    if (tabs == NULL)
      inserer(entite, code, type, val, 2, f, taille);
    else
      printf("entite existe deja\n");
    break;
  }
}

void afficher()
{

  int f;
  printf("/***************Table des symboles IDF*************/\n");
  printf("____________________________________________________________________\n");
  printf("\t| Nom_Entite |  Code_Entite   |  Type_Entite | Val_Entite   |    Taille    |\n");
  printf("____________________________________________________________________\n");
  for (f = 0; f < 300; f++)
  {
    tab = tab_hachage[f];
    while (tab != NULL)
    {
      printf("\t|%11s |%15s | %12s | %12f | %12s |\n", tab->name, tab->code, tab->type, tab->val, tab->taille);

      tab = tab->svt;
    }
  }

  printf("\n/***************Table des symboles mots clÃ©s*************/\n");

  printf("_____________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_____________________________________\n");
  for (f = 0; f < 300; f++)
  {
    tabm = tab_hachage_m[f];
    while (tabm != NULL)
    {
      printf("\t|%10s |%12s | \n", tabm->name, tabm->type);

      tabm = tabm->svt;
    }
  }

  printf("\n/***************Table des symboles sÃ©parateurs*************/\n");

  printf("_____________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_____________________________________\n");
  for (f = 0; f < 300; f++)
  {
    tabs = tab_hachage_s[f];
    while (tabs != NULL)
    {
      printf("\t|%10s |%12s | \n", tabs->name, tabs->type);

      tabs = tabs->svt;
    }
  }
}
