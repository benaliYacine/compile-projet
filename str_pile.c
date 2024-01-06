#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
typedef struct StackNode_str
{
    char *data;
    struct StackNode_str *next;
} StackNode_str;

// Function to create a new stack node
StackNode_str *newNode_str(char *data)
{
    StackNode_str *stackNode = (StackNode_str *)malloc(sizeof(StackNode_str));
    stackNode->data = strdup(data); // Use strdup to duplicate the string
    stackNode->next = NULL;
    return stackNode;
}

// Check if the stack is empty
int isEmpty_str(StackNode_str *root)
{
    return !root;
}

// Push a string onto the stack
void push_str(StackNode_str **root, char *data)
{
    StackNode_str *stackNode = newNode_str(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%s pushed to stack\n", data);
}

// Pop a string from the stack
char* pop_str(StackNode_str **root)
{
    if (isEmpty_str(*root))
        return NULL;
    StackNode_str *temp = *root;
    *root = (*root)->next;
    char *popped = temp->data;
    free(temp);
    return popped;
}

// Peek the top string of the stack
char* peek_str(StackNode_str *root)
{
    if (isEmpty_str(root))
        return NULL;
    return root->data;
}

// Main function to demonstrate stack operations
int main9()
{
    StackNode_str *stack1 = NULL;
    StackNode_str *stack2 = NULL;

    push_str(&stack1, "Hello");
    push_str(&stack1, "World");
    push_str(&stack1, "C Programming");

    push_str(&stack2, "Stack");
    push_str(&stack2, "Example");

    printf("%s popped from stack1\n", pop_str(&stack1));
    printf("Top of stack1 is %s\n", peek_str(stack1));

    printf("%s popped from stack2\n", pop_str(&stack2));
    printf("Top of stack2 is %s\n", peek_str(stack2));

    return 0;
}
