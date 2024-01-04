#ifndef ts_HASH_TABLE_H
#define ts_HASH_TABLE_H

typedef struct element_type1 *pointer_element1;

typedef struct element_type1
{
  char name[500];//bah ida str twiil yekfi
  char code[20];
  char type[20];
  char val[500];
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

bool isInteger(const char *str);

bool isFloat(const char *str);

bool isBoolean(const char *str);

char* GetType(char entite[]);

char* GetVal(char entite[]);

char* GetFct(char entite[]);

void initialisation();

int fonction_de_hachage(char name[20]);

void inserer(char entite[], char code[], char type[], char val[], int y, int hash_index, char taille[]);

int rechercher(char entite[], char code[], char type[], char val[], int y, char taille[], int P_OU_F);

void afficher();

#endif // ts_HASH_TABLE_H

