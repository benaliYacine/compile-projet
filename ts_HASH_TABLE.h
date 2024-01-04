#ifndef ts_HASH_TABLE_H
#define ts_HASH_TABLE_H

typedef struct element_type1 *pointer_element1;

typedef struct Multi_types
{
  int type;
  int entier;
  float reel;
  char *str;
  bool boolean;
} Multi_types;

typedef struct element_type1
{
  char name[20];
  char code[20];
  char type[20];
  Multi_types val;
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

int Declarer(char entite[]);

void inserer_fonction(char name_F[], int nb_argument);

int verifier_nb_argument(char name_F[], int nb_argument);

int are_compatible(garti op1, garti op2);

Multi_types add(Multi_types op1, Multi_types op2);

Multi_types sub(Multi_types op1, Multi_types op2);

Multi_types mul(Multi_types op1, Multi_types op2);

Multi_types div(Multi_types op1, Multi_types op2);

void initialisation();

int fonction_de_hachage(char name[20]);

void inserer(char *entite, char *code, char *type, Multi_types val, int y, int hash_index, char *taille);

int rechercher(char *entite, char *code, char *type, Multi_types val, int y, char *taille, int P_OU_F);

void afficher();

#endif // ts_HASH_TABLE_H
