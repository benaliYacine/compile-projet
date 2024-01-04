#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ts_HASH_TABLE.h"

// TS fcts

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

int verifier_in_out_table(char entite[],char CAZER[])
{
  int tab[100],i=0;
  char *token;
  int integer;
  int hash_index = fonction_de_hachage(entite);
  pointer_element1 tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL && strcmp(entite, tab_idf_pointer->name) != 0)
  {
    tab_idf_pointer = tab_idf_pointer->svt;
  }
  if(strlen(tab_idf_pointer->taille)!=strlen(CAZER))
    return 0;
  
  // Utilisation de strtok pour séparer la chaîne en tokens
  token = strtok(CAZER, ",");
  while (token != NULL)
  {
    
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    tab[i]=integer;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  
  token = strtok(tab_idf_pointer->taille, ",");
  i=0;
  while (token != NULL)
  {
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    if(tab[i]<0||tab[i]>=integer)
      return 0;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  return 1;
}

int fonction_de_hachage(char name[20])
{
  int i;
  int hashValue = 281;
  for (i = 0; name[i] != '\0'; i++)
  {
    hashValue = hashValue + name[i];
  }
  printf("---hash index: %d\n", hashValue % 300);
  return hashValue % 300;
}

void inserer(char entite[], char code[], char type[], char val[], int y, int hash_index, char taille[], int P_OU_F)
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
      strcpy(tab_idf_pointer->val, val);
      tab_idf_pointer->declarer = 0;
      if (P_OU_F)
        tab_idf_pointer->declarer = 1;
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

int rechercher(char entite[], char code[], char type[], char val[], int y, char taille[], int P_OU_F)
{
  printf("we have entered rechercher\n");
  printf("---valeur here is: %s\n", val);

  int hash_index = fonction_de_hachage(entite);
  // if(y>2){
  //   val= strtod(entite, NULL);
  //   y=0;
  // }
  switch (y)
  {
  case 0: /*verifier si la case dans la tables des IDF et CONST est libre*/

    printf("---we have entered case 0:\n");
    printf("---valeur here is: %s\n", val);
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
      inserer(entite, code, type, val, 0, hash_index, taille, P_OU_F);
    }
    else
    {
      if (strcmp(type, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        if (strcmp(type, "TABLEAU") == 0)
        {
          strcat(tab_idf_pointer->type, " ");
          strcat(tab_idf_pointer->type, "TABLEAU");
        }
        else
          strcpy(tab_idf_pointer->type, type);
      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
      if (taille != NULL && strcmp(taille, " ") != 0)
      { // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab_idf_pointer->taille, taille);

      } // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau

      if (val != NULL && strcmp(val, " ") != 0)
      {
        // hadi bah ki ya9a beli declarina tableau ybadal type ta3o yraj3o tableau
        strcpy(tab_idf_pointer->val, val);
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
      inserer(entite, code, type, val, 1, hash_index, taille, P_OU_F);
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
      inserer(entite, code, type, val, 2, hash_index, taille, P_OU_F);
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
    printf("______________________________________________________________________________________\n");
    printf("\t| Nom_Entite |  Code_Entite   |  Type_Entite    | Val_Entite   |    Taille    |\n");
    printf("_______________________________________________________________________________________\n");
    for (hash_index = 0; hash_index < 300; hash_index++)
    {
      tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
      while (tab_idf_pointer != NULL)
      {
        printf("\t|%11s |%15s | %15s | %12s | %12s |\n", tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille);
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

// semantique fcts

char *GetTypeFromVal(char entite[])
{
  if (isInteger(entite))
  {
    return "INTEGER";
  }
  else if (isFloat(entite))
  {
    return "FLOAT";
  }
  else if (isBoolean(entite))
  {
    return "BOOLEAN";
  }
  else
  {
    return " ";
  }
}

// Function to check if two entities are compatible
bool areCompatible(char entite1[], char entite2[])
{
  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, type2) == 0)
  { // Same type
    return true;
  }
  else if ((strcmp(type1, "INTEGER") == 0 && strcmp(type2, "FLOAT") == 0) ||
           (strcmp(type1, "FLOAT") == 0 && strcmp(type2, "INTEGER") == 0))
  {
    // INTEGER and FLOAT are compatible
    return true;
  }
  else
  {
    return false;
  }
}

int Operation(char op1[], char op2[])
{

  printf("%s\n", op1);
  int hash_index = fonction_de_hachage(op1);
  pointer_element1 tab_idf_pointer_1 = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer_1 != NULL && strcmp(op1, tab_idf_pointer_1->name) != 0)
  {
    tab_idf_pointer_1 = tab_idf_pointer_1->svt;
  }

  hash_index = fonction_de_hachage(op2);
  pointer_element1 tab_idf_pointer_2 = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer_2 != NULL && strcmp(op2, tab_idf_pointer_2->name) != 0)
  {
    tab_idf_pointer_2 = tab_idf_pointer_2->svt;
  }
  if (strcmp(tab_idf_pointer_1->type, tab_idf_pointer_2->type) == 0)
  {
    return 1;
  }

  else if (strcmp(tab_idf_pointer_1->type, "INTEGER") == 0 && strcmp(tab_idf_pointer_2->type, "REAL") == 0 || strcmp(tab_idf_pointer_2->type, "INTEGER") == 0 && strcmp(tab_idf_pointer_1->type, "REAL") == 0)
  {

    return 1;
  }
  else
    return 0;
}

int Declarer(char entite[])
{
  int hash_index = fonction_de_hachage(entite);
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL && strcmp(entite, tab_idf_pointer->name) != 0)
  {
    tab_idf_pointer = tab_idf_pointer->svt;
  }
  // printf("----------------%s\n", tab_idf_pointer->name);
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

bool isInteger(const char *str)
{ // hna const ghi optimization bah tgoul lel comilateur beli had l argument manich ra7 nmodifih koun
  char *end;
  strtol(str, &end, 10);
  return *end == '\0';
}

bool isFloat(const char *str)
{
  char *end;
  strtof(str, &end);
  return *end == '\0';
}

bool isBoolean(const char *str)
{
  return strcmp(str, "true") == 0 || strcmp(str, "false") == 0;
}

char *GetType(char entite[])
{
  int i;
  int hash_index = fonction_de_hachage(entite);
  while (i < 100 && LES_TABLES_IDF[i].state == 1)
  {
    // LES_TABLES_IDF[i].name;
    tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
    while (tab_idf_pointer != NULL)
    {
      if (!strcmp(tab_idf_pointer->name, entite))
      {
        return tab_idf_pointer->type;
      }
      else
      {
        tab_idf_pointer = tab_idf_pointer->svt;
      }
      // tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille tab_idf_pointer = tab_idf_pointer->svt;
    }
    i++;
  }
  if (tab_idf_pointer == NULL)
    return NULL;
}

char *GetVal(char entite[])
{
  int i;
  int hash_index = fonction_de_hachage(entite);
  while (i < 100 && LES_TABLES_IDF[i].state == 1)
  {
    // LES_TABLES_IDF[i].name;
    tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
    while (tab_idf_pointer != NULL)
    {
      if (!strcmp(tab_idf_pointer->name, entite))
      {
        return tab_idf_pointer->val;
      }
      else
      {
        tab_idf_pointer = tab_idf_pointer->svt;
      }
      // tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille tab_idf_pointer = tab_idf_pointer->svt;
    }
    i++;
  }
  if (tab_idf_pointer == NULL)
    return NULL;
}

char *GetFct(char entite[])
{
  int i;
  int hash_index = fonction_de_hachage(entite);
  while (i < 100 && LES_TABLES_IDF[i].state == 1)
  {
    tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
    while (tab_idf_pointer != NULL)
    {
      if (!strcmp(tab_idf_pointer->name, entite))
      {
        return LES_TABLES_IDF[i].name;
      }
      else
      {
        tab_idf_pointer = tab_idf_pointer->svt;
      }
    }
    i++;
  }
  if (tab_idf_pointer == NULL)
    return NULL;
}

int SetVal(char entite[], char val[])
{
  int i;
  int hash_index = fonction_de_hachage(entite);
  while (i < 100 && LES_TABLES_IDF[i].state == 1)
  {
    // LES_TABLES_IDF[i].name;
    tab_idf_pointer = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
    while (tab_idf_pointer != NULL)
    {
      if (!strcmp(tab_idf_pointer->name, entite))
      {
        strcpy(tab_idf_pointer->val, val);
        return 1;
      }
      else
      {
        tab_idf_pointer = tab_idf_pointer->svt;
      }
      // tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille tab_idf_pointer = tab_idf_pointer->svt;
    }
    i++;
  }
  if (tab_idf_pointer == NULL)
    return 0;
}
