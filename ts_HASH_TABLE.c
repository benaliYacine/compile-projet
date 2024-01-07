#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "ts_HASH_TABLE.h"

// TS fcts
char *return_val_fonction(char name[])
{
  int i = 0;
  int hash_index = fonction_de_hachage(name);
  while (LES_TABLES_IDF[i].state == 1 && strcmp(LES_TABLES_IDF[i].name, name) != 0)
    i++;
  pointer_element1 P_hash = NULL;
  P_hash = LES_TABLES_IDF[i].tab_hachage_idf[hash_index];
  while (strcmp(P_hash->name, name) != 0)
    P_hash = P_hash->svt;
  return P_hash->val;
}
char *return_val_tab(char name[], char taille1[])
{
  int j = 0, i = 0;
  while (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].state == 1 && strcmp(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].name, name) != 0)
  {
    j++;
  }
  char *token;
  char taille[20];
  int integer;
  int tab[2];
  strcpy(taille, taille1);
  token = strtok(taille, ",");
  for (i = 0; i < 2; i++)
  {
    tab[i] = 0;
  }
  i = 0;
  while (token != NULL)
  {
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    tab[i] = integer;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  if (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dementions == 1)
    return F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dim1[tab[0]].entite;
  else if (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dementions == 2)
    return F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dim2[tab[0]][tab[1]].entite;
}
/*
void afficher_tab() //zyada virifit brk
{
  int i = 0, j = 0, k = 0;
  int l = 0;
  for(i=0;i<3;i++)
  printf("%s\n", F_P_TABLE[0].Table_LES_TABLEAUX[0].dim2[1][1].entite);

}
*/
void A_M_tab(char name[], char taille1[], char val[])
{
  int i = 0;
  int j = 0;

  while (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].state == 1 && strcmp(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].name, name) != 0)
  {
    j++;
  }

  char *token;
  char taille[20];
  int integer;
  int tab[2];
  strcpy(taille, taille1);
  token = strtok(taille, ",");
  for (i = 0; i < 2; i++)
  {
    tab[i] = 0;
  }
  i = 0;
  while (token != NULL)
  {
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    tab[i] = integer;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  i = 0;
  if (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dementions == 1)
  {

    strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dim1[tab[0]].entite, val);
  }
  else
  {
    strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[j].dim2[tab[0]][tab[1]].entite, val);
  }
}
int initiali_tab(char name[], char taille1[])
{

  int tab1[2], i = 0, j = 0, k = 0, l = 0;
  int dimensions = 0;
  char *token;
  int integer;
  char taille[20];
  strcpy(taille, taille1);
  token = strtok(taille, ",");
  for (i = 0; i < 2; i++)
  {
    tab1[i] = 0;
  }
  i = 0;
  while (token != NULL)
  {
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    tab1[i] = integer;
    i++;
    dimensions++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  if (dimensions == 1)
  {
    i = 0;
    while (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].state == 1)
      i++;
    F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].state = 1;
    F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].dementions = 1;
    strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].name, name);
    for (j = 0; j < tab1[0]; j++)
      strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].dim1[j].entite, "");
  }
  if (dimensions == 2)
  {
    i = 0;
    while (F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].state == 1)
      i++;
    F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].state = 1;
    strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].name, name);
    F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].dementions = 2;
    for (j = 0; j < tab1[0]; j++)
      for (k = 0; k < tab1[1]; k++)
        strcpy(F_P_TABLE[POSITION_F_P_tables].Table_LES_TABLEAUX[i].dim2[j][k].entite, "");
  }
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

int verifier_in_out_table(char entite[], char CAZER[])
{
  int tab[100], i = 0, j = 0;
  char *token;
  int integer;
  char taille[20];
  char taille2[20];
  int hash_index = fonction_de_hachage(entite);
  pointer_element1 tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL && strcmp(entite, tab_idf_pointer->name) != 0)
  {
    tab_idf_pointer = tab_idf_pointer->svt;
  }
  // Utilisation de strtok pour séparer la chaîne en tokens
  strcpy(taille2, CAZER);
  token = strtok(taille2, ",");
  while (token != NULL)
  {

    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    tab[i] = integer;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  strcpy(taille, tab_idf_pointer->taille);
  token = strtok(taille, ",");
  j = i;
  i = 0;
  while (token != NULL)
  {
    // Utilisation de atoi pour convertir le token en entier
    integer = atoi(token);
    if (tab[i] < 0 || tab[i] >= integer)
      return 0;
    i++;
    // Passage au token suivant
    token = strtok(NULL, ",");
  }
  if (j != i)
    return 0;
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
      POSITION_F_P_tables++;
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

//  semantique fcts

char *GetTypeFromVal(char entite[])
{
  if (isInteger(entite))
  {
    return "INTEGER";
  }
  else if (isFloat(entite))
  {
    return "REAL";
  }
  else if (isBoolean(entite))
  {
    return "LOGICAL";
  }
  else if (isString(entite))
  {
    return "CHARACTER";
  }
  else
  {
    return " ";
  }
}

// Helper function to determine if an entity is a type string
bool isTypeString(char *entity)
{
  printf("type entite: %s\n", entity);
  if (strstr(entity, "INTEGER") != NULL ||
      strstr(entity, "REAL") != NULL ||
      strstr(entity, "CHARACTER") != NULL ||
      strstr(entity, "ARGUMENT") != NULL ||
      strstr(entity, "LOGICAL") != NULL)
  {
    return true;
  }
  else
    return false;
}

// Function to check if two entities are compatible
bool areCompatible(char entite1[], char entite2[])
{

  char *type1, *type2;

  printf("\n\n------------we want to compare %s with %s\n\n", entite1, entite2);

  if (isTypeString(entite1))
  {
    type1 = strdup(entite1); // Directly use the entity as its type
  }
  else
  {
    type1 = strdup(GetTypeFromVal(entite1)); // Determine type using GetTypeFromVal
  }

  if (isTypeString(entite2))
  {
    type2 = strdup(entite2); // Directly use the entity as its type
  }
  else
  {
    type2 = strdup(GetTypeFromVal(entite2)); // Determine type using GetTypeFromVal
  }

  printf("\n\n------------now we want to compare %s with %s\n\n", type1, type2);
  if (strstr(type1, type2) != NULL || strstr(type1, "ARGUMENT") != NULL || strstr(type2, "ARGUMENT") != NULL)
  { // Same type
    return true;
  }
  if (strstr(type1, "REAL") != NULL && strstr(type2, "INTEGER") != NULL)
    return true;
  else
  {
    return false;
  }
}

// Function to check if arithmetic operations can be performed on two entities
bool canPerformArithmetic(char entite1[], char entite2[])
{
  char *type1;
  char *type2;
  
  type1 = strdup(GetTypeFromVal(entite1)); // Determine type using GetTypeFromVal
  type2 = strdup(GetTypeFromVal(entite2)); // Determine type using GetTypeFromVal
  if (strcmp(type1," ")==0 || strcmp(type2," ")==0){
    return true;
  }


  printf("\n\n------------entities are= %s,%s\n\n", entite1, entite2);
  printf("\n\n------------types are= %s,%s\n\n", type1, type2);
  // Check if both types are either INTEGER or FLOAT
  bool isType1Numeric = (strstr(type1, "INTEGER") != NULL || strstr(type1, "REAL") != NULL || strstr(type1, "ARGUMENT") != NULL);
  bool isType2Numeric = (strstr(type2, "INTEGER") != NULL || strstr(type2, "REAL") != NULL || strstr(type2, "ARGUMENT") != NULL);

  return isType1Numeric && isType2Numeric;
}

char *addEntities(char entite1[], char entite2[])
{
  static char backToStr[20]; // Static to return it from the function

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    sprintf(backToStr, "%d", val1 + val2);
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    sprintf(backToStr, "%g", val1 + val2);
  }

  return backToStr;
}
char *subEntities(char entite1[], char entite2[])
{
  static char backToStr[20]; // Static to return it from the function

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    sprintf(backToStr, "%d", val1 - val2);
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    sprintf(backToStr, "%g", val1 - val2);
  }

  return backToStr;
}

char *mulEntities(char entite1[], char entite2[])
{
  static char backToStr[20]; // Static to return it from the function

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    sprintf(backToStr, "%d", val1 * val2);
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    sprintf(backToStr, "%g", val1 * val2);
  }

  return backToStr;
}
char *divEntities(char entite1[], char entite2[])
{
  static char backToStr[20]; // Static to return it from the function

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    sprintf(backToStr, "%d", val1 * val2);
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    sprintf(backToStr, "%g", val1 * val2);
  }

  return backToStr;
}

char *ltEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    printf("\n\n------------here is the two ints we want to compare %d,%d\n\n", val1, val2);
    return (val1 < val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 < val2) ? "true" : "false";
  }
}
char *gtEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    return (val1 > val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 > val2) ? "true" : "false";
  }
}
char *geEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    return (val1 >= val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 >= val2) ? "true" : "false";
  }
}
char *eqEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    return (val1 == val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 == val2) ? "true" : "false";
  }
}
char *neEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    return (val1 != val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 != val2) ? "true" : "false";
  }
}
char *leEntities(char entite1[], char entite2[])
{

  char *type1 = GetTypeFromVal(entite1);
  char *type2 = GetTypeFromVal(entite2);

  if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "INTEGER") == 0)
  {
    int val1 = strtol(entite1, NULL, 10);
    int val2 = strtol(entite2, NULL, 10);
    return (val1 <= val2) ? "true" : "false";
  }
  else
  {
    float val1 = (strcmp(type1, "INTEGER") == 0) ? (float)strtol(entite1, NULL, 10) : strtof(entite1, NULL);
    float val2 = (strcmp(type2, "INTEGER") == 0) ? (float)strtol(entite2, NULL, 10) : strtof(entite2, NULL);
    return (val1 <= val2) ? "true" : "false";
  }
}

float convertStrToFloat(char *entite)
{
  if (isInteger(entite))
  {
    int val = strtol(entite, NULL, 10);
    return (float)val; // Convert integer to float
  }
  else if (isFloat(entite))
  {
    return strtof(entite, NULL); // Already a float
  }
  else
  {
    // Handle the case where the string is neither an integer nor a float
    // This could be an error or a default value, depending on your application
    return 0.0f; // Example: default to 0.0
  }
}

// Function to check if the entity is "zero"
bool isEntityZero(char *entite)
{
  float value = convertStrToFloat(entite);
  const float epsilon = 1e-6; // Small threshold for floating point comparison

  return fabs(value) < epsilon;
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
  else if (TABLE_DES_FONCTION_NB_ARG[i].state == 0)
    return -1;
  else if (TABLE_DES_FONCTION_NB_ARG[i].nb_argument != nb_argument)
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

bool isString(const char *str)
{
  // Check if the first character is a double quote
  if (str[0] != '\"')
    return false;

  // Check if the last character is a double quote and it's not the same as the first character
  if (str[strlen(str) - 1] != '\"' || strlen(str) == 1)
    return false;

  return true;
}

char *GetTypeFromTS(char entite[])
{

  int hash_index = fonction_de_hachage(entite);
  // LES_TABLES_IDF[i].name;
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL)
  {
    if (!strcmp(tab_idf_pointer->name, entite))
    {
      printf("\n\n------------we have %s with type %s\n\n", tab_idf_pointer->name, tab_idf_pointer->type);
      return tab_idf_pointer->type;
    }
    else
    {
      tab_idf_pointer = tab_idf_pointer->svt;
    }
    // tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille tab_idf_pointer = tab_idf_pointer->svt;
  }

  if (tab_idf_pointer == NULL)
    return NULL;
}

char *GetValFromTS(char entite[])
{
  int hash_index = fonction_de_hachage(entite);
  // LES_TABLES_IDF[i].name;
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
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

  if (tab_idf_pointer == NULL)
    return NULL;
}

char *GetFctFromTS(char entite[])
{
  int hash_index = fonction_de_hachage(entite);
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL)
  {
    if (!strcmp(tab_idf_pointer->name, entite))
    {
      return LES_TABLES_IDF[POSITION_Tables_IDF].name;
    }
    else
    {
      tab_idf_pointer = tab_idf_pointer->svt;
    }
  }
  if (tab_idf_pointer == NULL)
    return NULL;
}

int SetValInTS(char entite[], char val[])
{
  printf("\n\n------------we want to put %s in %s\n\n", val, entite);
  int hash_index = fonction_de_hachage(entite);
  // LES_TABLES_IDF[i].name;
  tab_idf_pointer = LES_TABLES_IDF[POSITION_Tables_IDF].tab_hachage_idf[hash_index];
  while (tab_idf_pointer != NULL)
  {
    if (!strcmp(tab_idf_pointer->name, entite))
    {
      printf("\n\n------------we have put %s in %s\n\n", val, tab_idf_pointer->name);
      strcpy(tab_idf_pointer->val, val);
      return 1;
    }
    else
    {
      tab_idf_pointer = tab_idf_pointer->svt;
    }
    // tab_idf_pointer->name, tab_idf_pointer->code, tab_idf_pointer->type, tab_idf_pointer->val, tab_idf_pointer->taille tab_idf_pointer = tab_idf_pointer->svt;
  }

  if (tab_idf_pointer == NULL)
  {
    printf("\n\n------------we could not put %s in %s\n\n", val, tab_idf_pointer);
    return 0;
  }
}

char *Cree_temp()
{
  static int counter = 1;  // Static counter, retains its value between function calls
  char *name = malloc(10); // Allocate memory for the string

  if (name == NULL)
  {
    // Handle memory allocation failure
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  sprintf(name, "T%d", counter); // Format the string
  counter++;                     // Increment the counter

  return name;
}

char *Cree_temp_cond()
{
  static int counter = 1;  // Static counter, retains its value between function calls
  char *name = malloc(10); // Allocate memory for the string

  if (name == NULL)
  {
    // Handle memory allocation failure
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  sprintf(name, "temp_cond%d", counter); // Format the string
  counter++;                             // Increment the counter

  return name;
}
char *Calculer_type(char type1[], char type2[])
{
  if (strstr(type1, "REAL") != NULL || strstr(type2, "REAL") != NULL)
  {
    return "REAL";
  }
  else
  {
    return "INTEGER";
  }
}
