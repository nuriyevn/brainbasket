#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

#define STACK_MAX 100


struct Stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;


void Stack_Init(Stack *S)
{
    S->size = 0;
}

int Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } 

    return S->data[S->size-1];
}

void Stack_Push(Stack *S, int d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

void Stack_Print(Stack *S)
{
    for (int i = 0; i < S->size; i++)
    {
        printf("[%d]=%d; ", i, S->data[i] );
    }
    printf("\n");
}

int main()
{
    
    char op;
    // Declaration of stack structure
    Stack my_stack;
    
    // Initializing my stack 
    // we should initialize once
    Stack_Init(&my_stack);
    
    // 'u' = push
    // 'o' = pop
    // 't' = top
    // 'p' = print
    // 'q' = quit;
    
    while ((op = GetChar()))
    {
        if (op == 'u')
        {
            int d = GetInt();
            Stack_Push(&my_stack, d);
        }
        else if (op == 'o')
        {
            int top = Stack_Top(&my_stack);
            printf("We will delete %d\n", top );
            Stack_Pop(&my_stack);
        }
        else if (op == 't')
        {   
            printf("Top element = %d", Stack_Top(&my_stack));
        }
        else if (op == 'p')
        {
            Stack_Print(&my_stack);
        }
        else if (op == 'q')
        {
            break;
        }
        else
        {
            printf("Invalid command. Please, try again\n");
        }
    }
    
    
}