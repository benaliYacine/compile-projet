#include <stdbool.h> // For boolean type in C
#include <string.h>  // For string operations

#define TABLE_SIZE 100
#define NAME_SIZE 20

typedef struct
{
    char fct_nom[NAME_SIZE];
    bool util;
    int address;
} FunctionTable;

FunctionTable table_fct[TABLE_SIZE];
int index_table_fct = -1;

int lookup(const char *name)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (strcmp(table_fct[i].fct_nom, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int inserer_fct(const char *name, bool util, int address)
{
    int i;
    if (index_table_fct < 99)
    {
        index_table_fct++;
        strncpy(table_fct[index_table_fct].fct_nom, name, NAME_SIZE - 1);
        table_fct[index_table_fct].fct_nom[NAME_SIZE - 1] = '\0'; // Ensure null-termination
        table_fct[index_table_fct].util = util;
        table_fct[index_table_fct].address = address;
        return index_table_fct;
    }
    else
    {
        return -1;
    }
}

void show_table()
{
    printf("Table Contents:\n");
    printf("Index\tName\t\tUtil\tAddress\n");
    int i;
    for (i = 0; i <= index_table_fct; i++)
    {
        printf("%d\t%s\t\t%d\t%d\n", i, table_fct[i].fct_nom, table_fct[i].util, table_fct[i].address);
    }
}
