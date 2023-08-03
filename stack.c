#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char data;
    void *prev;
} Node;

Node *top = NULL;

void push(char data)
{
    Node *new = malloc(sizeof(Node));

    if (new == NULL)
    {
        printf("Error");
    }
    else
    {
        new->data = data;
        new->prev = top;
        top = new;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Error");
    }
    else
    {
        Node *temp = top;
        top = top->prev;
        free(temp);
        temp = NULL;
    }
}

void print()
{
    Node *current = top;
    while (current != NULL)
    {
        printf("%c", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    print();

    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    print();

    pop();
    pop();
    pop();
    pop();
    print();
    
    return 0;
}