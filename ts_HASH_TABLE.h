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
  int declarer;
  pointer_element1 svt;
} element_type1;

typedef struct element_type2 *pointer_element2;

typedef struct element_type2
{
  char name[20];
  char type[20];
  pointer_element2 svt;
} element_type2;

typedef struct Table_Pointers_Sur_Tables_IDF
{
  int state;
  char name[20];
  pointer_element1 tab_hachage_idf[300];
} Table_Pointers_Sur_Tables_IDF;

typedef struct Table_Arguments_Fonction
{
  char name[20];
  int state;
  int nb_argument;
} Table_Arguments_Fonction;

Table_Arguments_Fonction TABLE_DES_FONCTION_NB_ARG[100];
Table_Pointers_Sur_Tables_IDF LES_TABLES_IDF[100];
int POSITION_Tables_IDF = -1;
// idf const
pointer_element2 tab_hachage_mot_cle[300], tab_hachage_sepa[300];
pointer_element1 tab_idf_pointer = NULL, prd = NULL;
pointer_element2 tab_mot_cle_pointer = NULL, tab_sepa_pointer = NULL, prdm = NULL, prds = NULL;

int Declarer(char entite[])
{
  int hash_index = fonction_de_hachage(entite);
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL && strcmp(entite, tab_idf_pointer->name) != 0)
  {
    tab_idf_pointer = tab_idf_pointer->svt;
  }
  printf("----------------%s\n", tab_idf_pointer->name);
  if (tab_idf_pointer != NULL)
    if (tab_idf_pointer->declarer == 1)
    {
      return 1;
    }
    else
    {
      tab_idf_pointer->declarer = 1;
      return 0;
    }
}

void inserer_fonction(char name_F[], int nb_argument)
{
  int i = 0;
  while (TABLE_DES_FONCTION_NB_ARG[i].state == 1)
  {
    i++;
  }
  TABLE_DES_FONCTION_NB_ARG[i].state = 1;
  TABLE_DES_FONCTION_NB_ARG[i].nb_argument = nb_argument;
  strcpy(TABLE_DES_FONCTION_NB_ARG[i].name, name_F);
}

int verifier_nb_argument(char name_F[], int nb_argument)
{
  int i = 0;
  while (TABLE_DES_FONCTION_NB_ARG[i].state == 1 && strcmp(TABLE_DES_FONCTION_NB_ARG[i].name, name_F) != 0)
    i++;
  if (TABLE_DES_FONCTION_NB_ARG[i].state == 1 && TABLE_DES_FONCTION_NB_ARG[i].nb_argument == nb_argument)
    return 0;
  else
    return 1;
}

void initialisation()
{
  int i, j;
  for (i = 0; i < 300; i++)
  {
    tab_hachage_sepa[i] = NULL;
    tab_hachage_mot_cle[i] = NULL;
  }
  for (i = 0; i < 100; i++)
  {
    TABLE_DES_FONCTION_NB_ARG[i].state = 0;
    LES_TABLES_IDF[i].state = 0;
  }
  for (j = 0; j < 300; j++)
  {
    LES_TABLES_IDF[i].tab_hachage_idf[j] = NULL;
  }
}

int fonction_de_hachage(char name[20])
{
  int index = ((int)name[0] + (int)name[1]) % 300;
  printf("----index:%d", index);
  return index;
}

void inserer(char entite[], char code[], char type[], float val, int y, int hash_index, char taille[])
{
  switch (y)
  {

  case 0: /*insertion dans la table des IDF et CONST*/

    tab_idf_pointer = malloc(sizeof(element_type1));
    if (tab_idf_pointer == NULL)
      printf("memoire plein\n");
    else
    {

      strcpy(tab_idf_pointer->name, entite);
      strcpy(tab_idf_pointer->code, code);
      strcpy(tab_idf_pointer->type, type);
      tab_idf_pointer->val = val;
      tab_idf_pointer->declarer = 0;
      tab_idf_pointer->svt = NULL;
      if (taille == NULL)
      {
        strcpy(tab_idf_pointer->taille, " ");
      }
      else
        strcpy(tab_idf_pointer->taille, taille);
      if (LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index] == NULL)
      {
        LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index] = tab_idf_pointer;
      }
      else
      {
        prd = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
        while (prd->svt != NULL)
          prd = prd->svt;
        prd->svt = tab_idf_pointer;
      }
    }
    break;

  case 1: /*insertion dans la table des mots clÃ©s*/
    tab_mot_cle_pointer = malloc(sizeof(element_type2));
    if (tab_mot_cle_pointer == NULL)
      printf("memoire plein\n");
    else
    {
      strcpy(tab_mot_cle_pointer->name, entite);
      strcpy(tab_mot_cle_pointer->type, code);
      tab_mot_cle_pointer->svt = NULL;
      if (tab_hachage_mot_cle[hash_index] == NULL)
      {
        tab_hachage_mot_cle[hash_index] = tab_mot_cle_pointer;
      }
      else
      {
        prdm = tab_hachage_mot_cle[hash_index];
        while (prdm->svt != NULL)
          prdm = prdm->svt;
        prdm->svt = tab_mot_cle_pointer;
      }
    }
    break;

  case 2: /*insertion dans la table des sepa*/
    tab_sepa_pointer = malloc(sizeof(element_type2));

    if (tab_sepa_pointer == NULL)
      printf("memoire plein\n");
    else
    {
      strcpy(tab_sepa_pointer->name, entite);
      strcpy(tab_sepa_pointer->type, code);
      tab_sepa_pointer->svt = NULL;
      if (tab_hachage_sepa[hash_index] == NULL)
      {
        tab_hachage_sepa[hash_index] = tab_sepa_pointer;
      }
      else
      {
        prdm = tab_hachage_sepa[hash_index];
        while (prds->svt != NULL)
          prds = prds->svt;
        prds->svt = tab_sepa_pointer;
      }
      break;
    }
  }
}

int rechercher(char entite[], char code[], char type[], float val, int y, char taille[], int P_OU_F)
{
  printf("dkhalna l rech\n");
  int hash_index = fonction_de_hachage(entite);
  switch (y)
  {
  case 0: /*verifier si la case dans la tables des IDF et CONST est libre*/

    printf("---valeur f rech: %f\n", val);
    if (P_OU_F == 1)
    {
      POSITION_Tables_IDF++;
      LES_TABLES_IDF[POSITION_Tables_IDF].state = 1;
      strcpy(LES_TABLES_IDF[POSITION_Tables_IDF].name, entite);
    }
    tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
    while (tab_idf_pointer != NULL && strcmp(entite, tab_idf_pointer->name) != 0)
    {
      printf("---tab_idf_pointer: %d\n", tab_idf_pointer);
      tab_idf_pointer = tab_idf_pointer->svt;
    }
    if (tab_idf_pointer == NULL)
    {
      printf("---jddiiid\n");
      inserer(entite, code, type, val, 0, hash_index, taille);
      return 0;
    }
    else
    {
      if (strcmp(type, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab_idf_pointer->type, type);

      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
      if (strcmp(taille, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab_idf_pointer->taille, taille);
      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
      if (tab_idf_pointer->val == 0.0)
      {
        // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        tab_idf_pointer->val = val;
      }
      printf("entite existe deja\n");
      return 1;
    }
    break;

  case 1: /*verifier si la case dans la tables des mots clÃ©s est libre*/
    tab_mot_cle_pointer = tab_hachage_mot_cle[hash_index];

    while (tab_mot_cle_pointer != NULL && strcmp(entite, tab_mot_cle_pointer->name) != 0)
    {
      tab_mot_cle_pointer = tab_mot_cle_pointer->svt;
    }
    if (tab_mot_cle_pointer == NULL)
      inserer(entite, code, type, val, 1, hash_index, taille);
    else
      printf("entite existe deja\n");
    break;

  case 2: /*verifier si la case dans la tables des sÃ©parateurs est libre*/
    tab_sepa_pointer = tab_hachage_sepa[hash_index];

    while (tab_sepa_pointer != NULL && strcmp(entite, tab_sepa_pointer->name) != 0)
    {
      tab_sepa_pointer = tab_sepa_pointer->svt;
    }
    if (tab_sepa_pointer == NULL)
      inserer(entite, code, type, val, 2, hash_index, taille);
    else
      printf("entite existe deja\n");
    break;
  }
}

void afficher()
{

  int hash_index, i = 0;

  while (i < 100 && LES_TABLES_IDF[i].state == 1)
  {
    printf("/******************Table des symboles IDF De %s****************/ \n", LES_TABLES_IDF[i].name);
    printf("___________________________________________________________________________________\n");
    printf("\t| Nom_Entite |  Code_Entite   |  Type_Entite | Val_Entite   |    Taille    |\n");
    printf("____________________________________________________________________________________\n");
    for (hash_index = 0; hash_index < 300; hash_index++)
    {
      tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
      while (tab_idf_pointer != NULL)
      {
        printf("\t|%11s |%15s | %12s | %12f | %12s |\n", tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille);
        tab_idf_pointer = tab_idf_pointer->svt;
      }
    }
    printf("\n");
    i++;
  }

  printf("\n/***************Table des symboles mots cles*************/\n");

  printf("_____________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_____________________________________\n");
  for (hash_index = 0; hash_index < 300; hash_index++)
  {
    tab_mot_cle_pointer = tab_hachage_mot_cle[hash_index];
    while (tab_mot_cle_pointer != NULL)
    {
      printf("\t|%10s |%12s | \n", tab_mot_cle_pointer->name, tab_mot_cle_pointer->type);

      tab_mot_cle_pointer = tab_mot_cle_pointer->svt;
    }
  }

  printf("\n/***************Table des symboles sepa*************/\n");

  printf("_____________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_____________________________________\n");
  for (hash_index = 0; hash_index < 300; hash_index++)
  {
    tab_sepa_pointer = tab_hachage_sepa[hash_index];
    while (tab_sepa_pointer != NULL)
    {
      printf("\t|%10s |%12s | \n", tab_sepa_pointer->name, tab_sepa_pointer->type);

      tab_sepa_pointer = tab_sepa_pointer->svt;
    }
  }
}
