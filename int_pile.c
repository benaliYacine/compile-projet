#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct StackNode_int
{
    int data;
    struct StackNode_int *next;
} StackNode_int;

// Function to create a new stack node
StackNode_int *newNode_int(int data)
{
    StackNode_int *stackNode = (StackNode_int *)malloc(sizeof(StackNode_int));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Check if the stack is empty
int isEmpty_int(StackNode_int *root)
{
    return !root;
}

// Push an item onto the stack
void push_int(StackNode_int **root, int data)
{
    StackNode_int *stackNode = newNode_int(data);
    stackNode->next = *root;
    *root = stackNode;
    // printf("%d pushed to stack\n", data);
}

// Pop an item from the stack
int pop_int(StackNode_int **root)
{
    if (isEmpty_int(*root))
        return 0;
    StackNode_int *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Peek the top item of the stack
int peek_int(StackNode_int *root)
{
    if (isEmpty_int(root))
        return 0;
    return root->data;
}

// Main function to demonstrate stack operations
int main2()
{
    StackNode_int *stack1 = NULL;
    StackNode_int *stack2 = NULL;

    push_int(&stack1, 10);
    push_int(&stack1, 20);
    push_int(&stack1, 30);

    push_int(&stack2, 40);
    push_int(&stack2, 50);

    printf("%d popped from stack1\n", pop_int(&stack1));
    printf("Top of stack1 is %d\n", peek_int(stack1));

    printf("%d popped from stack2\n", pop_int(&stack2));
    printf("Top of stack2 is %d\n", peek_int(stack2));

    return 0;
}
