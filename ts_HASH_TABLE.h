#ifndef ts_HASH_TABLE_H
#define ts_HASH_TABLE_H

typedef struct element_type1 *pointer_element1;

typedef struct element_type1
{
  char name[500]; // bah ida str twiil yekfi
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

typedef struct table_string
{
  char entite[20];
} table_string;
typedef struct table_les_tableaux
{
  char name[20];
  int state;
  int dementions;
  table_string dim1[200];
  table_string dim2[200][200];
} table_les_tableaux;
typedef struct F_P_tables
{
  table_les_tableaux Table_LES_TABLEAUX[50];
} F_P_tables;

F_P_tables F_P_TABLE[20];

Table_Arguments_Fonction TABLE_DES_FONCTION_NB_ARG[100];
Table_Pointers_Sur_Tables_IDF LES_TABLES_IDF[100];
int POSITION_Tables_IDF = -1;
int POSITION_F_P_tables = -1;
// idf const
pointer_element2 tab_hachage_mot_cle[300], tab_hachage_sepa[300];
pointer_element1 tab_idf_pointer = NULL, prd = NULL;
pointer_element2 tab_mot_cle_pointer = NULL, tab_sepa_pointer = NULL, prdm = NULL, prds = NULL;

int fonction_de_hachage(char name[20]);

void inserer(char entite[], char code[], char type[], char val[], int y, int hash_index, char taille[], int P_OU_F);

int rechercher(char entite[], char code[], char type[], char val[], int y, char taille[], int P_OU_F);

void afficher();

char *return_val_tab(char name[], char taille1[]);

void A_M_tab(char name[], char taille1[], char val[]);

void initiali_tab(char name[], char taille1[]);

void initialisation();

int verifier_in_out_table(char entite[], char CAZER[]);

char *GetTypeFromVal(char entite[]);

bool isTypeString(char *entity);

bool areCompatible(char entite1[], char entite2[]);

bool canPerformArithmetic(char entite1[], char entite2[]);

char *addEntities(char entite1[], char entite2[]);

char *subEntities(char entite1[], char entite2[]);

char *mulEntities(char entite1[], char entite2[]);

char *divEntities(char entite1[], char entite2[]);

char *ltEntities(char entite1[], char entite2[]);

char *gtEntities(char entite1[], char entite2[]);

char *geEntities(char entite1[], char entite2[]);

char *eqEntities(char entite1[], char entite2[]);

char *neEntities(char entite1[], char entite2[]);

char *leEntities(char entite1[], char entite2[]);

float convertStrToFloat(char *entite);

bool isEntityZero(char *entite);

int Operation(char op1[], char op2[]);

int Declarer(char entite[]);

void inserer_fonction(char name_F[], int nb_argument);

int verifier_nb_argument(char name_F[], int nb_argument);

bool isInteger(const char *str);

bool isFloat(const char *str);

bool isBoolean(const char *str);

bool isString(const char *str);

bool isCharacter(const char *str);
char *GetTypeFromTS(char entite[]);

char *GetValFromTS(char entite[]);

char *GetFctFromTS(char entite[]);

int SetValInTS(char entite[], char val[]);

char *Cree_temp();

char *Cree_temp_cond();

char *Calculer_type(char type1[], char type2[]);

bool canBeBoolean(char *entite);

#endif // ts_HASH_TABLE_H
