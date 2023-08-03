#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int data;
    void *prev;
    void *next;
} Node;

Node *head = NULL;

Node *getNewNode(int data)
{
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

Node *insertHead(int data)
{
    Node *new = getNewNode(data);

    if (new == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    if (head != NULL)
    {

        new->next = head;
        head->prev = new;
    }

    head = new;

    return new;
}

Node *insertTail(int data)
{
    Node *new = getNewNode(data);

    if (new == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new;
    new->prev = tail;

    return new;
}

int removeValue(int value){
    Node *current = head;
    while(current != NULL){
        if(current->data == value){
            if(current->prev != NULL){
                Node *temp = current->prev;
                temp->next = current->next;
                temp = current->next;
                temp->prev = current->prev;
            }
            else{
                head = current->next;
                head->prev = NULL;
            }
            free(current);
            current = NULL;
            return 1;
        }
        else
            current = current-> next;
    }
    return 0;
}

void reverseList()
{
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev; // since the temp->prev still holds the last node of the original list which is the new head
}

void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printReverse()
{
    Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    insertHead(5);
    insertHead(4);
    insertHead(3);
    insertHead(2);
    insertHead(1);
    printList();
    printReverse();

    insertTail(6);
    insertTail(7);
    insertTail(8);
    insertTail(9);
    insertTail(10);
    printList();
    printReverse();

    reverseList();
    printList();
    printReverse();

    removeValue(5);
    reverseList();
    printList();
    printReverse();
    return 0;
}
