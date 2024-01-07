#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    char non_terminal_name[40];
    char operande_name[20];
    char operande_type[20];
    struct StackNode *next;
} StackNode;

StackNode *newNode(const char *non_terminal, const char *operande_name, const char *operande_type)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    strcpy(stackNode->non_terminal_name, non_terminal);
    strcpy(stackNode->operande_name, operande_name);
    strcpy(stackNode->operande_type, operande_type);
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, const char *non_terminal, const char *operande_name, const char *operande_type)
{
    StackNode *stackNode = newNode(non_terminal, operande_name, operande_type);
    stackNode->next = *root;
    *root = stackNode;
    // printf("Item pushed to stack: %S\n",operande_name);
}

StackNode *pop(StackNode **root)
{
    if (isEmpty(*root))
        return NULL;
    StackNode *temp = *root;
    *root = (*root)->next;
    return temp;
}

void afficher_pile(StackNode *root)
{
    StackNode *current = root;

    printf("----------Operande Pile-------------\n");
    printf("| Non-terminal: | Operande: | Type: |--> must be umpty at the end\n");

    while (current != NULL)
    {
        printf("Non-terminal: %s, Operande: %s, Type: %s\n",
               current->non_terminal_name, current->operande_name, current->operande_type);
        current = current->next;
    }
}

int main6()
{
    StackNode *stack = NULL;

    // Pushing elements to the stack
    push(&stack, "NonTerminal1", "Operande1", "Type1");
    push(&stack, "NonTerminal2", "Operande2", "Type2");

    // Popping an element and printing its operande_name
    StackNode *poppedElement = pop(&stack);
    if (poppedElement != NULL)
    {
        // printf("Popped element's operande_name: %s\n", poppedElement->operande_name);
        free(poppedElement); // Free the popped element
    }

    // Clean up remaining elements in the stack
    while (!isEmpty(stack))
    {
        StackNode *temp = pop(&stack);
        free(temp);
    }

    return 0;
}
