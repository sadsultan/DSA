#include <stdio.h>
#include <stdlib.h>

typedef struct
{               // typedef is used to make this its own type instead of a struct
    int data;   // data we want to store
    void *next; // second value is the pointer to the next node so we give it the next node as is and since it has the * it is the pointer of next node
} Node;

Node *head = NULL; // define the head of the list as empty

Node *addNode(int data)
{
    Node *newNode = malloc(sizeof(Node)); // allocate the memory for the new node

    // for empty list
    if (head == NULL)
    {
        if (newNode == NULL)
        {
            printf("Error allocating memory\n");
            return NULL;
        }
        newNode->data = data;
        newNode->next = NULL; // since the current head is to be the terminator of the list
        head = newNode;
    }

    // for non-empty list
    else
    {
        if (newNode == NULL)
        {
            printf("Error allocating memory\n");
            return NULL;
        }

        newNode->data = data;
        newNode->next = head; // since the current head is to be the next node
        head = newNode;
    }

    return newNode; // returning the new node brings it in scope of the main function
}

void printMenu()
{
    printf("Linked List\n");
    printf("Your options are:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Enter data at specific node\n");
    printf("4. Print\n");
    printf("5. Exit\n");
    printf("6. Reverse\n");
    printf("7. Print reverse recursively\n");
}

void printList()
{
    Node *current = head; // make a pointer that points to the head of the list
    while (current != NULL)
    {
        printf("%d\n", current->data); // print the node data
        current = current->next;       // make current the pointer to the next node in line
    }
}

Node *addSpecificPosition(int position, int data)
{

    Node *current = head;
    position--;
    // traverse the list to find the position
    while (current != NULL && position > 0)
    {
        current = current->next;
        position--;
    }

    // if list ended before position was found
    if (position != 0)
    {
        printf("Position not found\n");
        return NULL;
    }

    // if position was found add node as before
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }
    else
    {
        new->data = data;
        new->next = current->next;
        current->next = new;
    }
    return;
}

int removeNode(int data)
{
    Node *current = head;
    Node *prev = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current == head)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
                free(current);  // free the memory at the pointer
                current = NULL; // set the pointer to NULL
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

void reverseList()
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void recursiveReverse(Node *current)
{
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    recursiveReverse(current->next);
    Node *temp = current->next;
    temp->next = current;
    current->next = NULL;
}

void recursiveReversePrint(Node *head)
{
    if (head == NULL)
        return;
    recursiveReversePrint(head->next);
    printf("%d\n", head->data);
}

int main()
{
    int option = 0;
    while (option != 5)
    {
        printMenu();
        scanf("%d", &option);
        int user_in = 0;
        switch (option)
        {
        case 1:
            printf("Enter your data:\n");
            scanf("%d", &user_in);
            printf("Adding node with data %d\n", user_in);
            addNode(user_in);
            break;
        case 2:
            printf("Enter the data to remove:\n");
            scanf("%d", &user_in);
            printf("Removing node with data %d\n", user_in);
            if (removeNode(user_in))
                printf("Node removed\n");
            else
                printf("Node not found\n");
            break;
        case 3:
            int data;
            printf("Enter the position:\n");
            scanf("%d", &user_in);
            printf("Enter the data:\n");
            scanf("%d", &data);
            addSpecificPosition(user_in, data);
            break;
        case 4:
            printf("Printing list\n");
            printList();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        case 6:
            printf("Reversing list\n");
            reverseList();
            break;
        case 7:
            printf("Printing reverse of list recursively\n");
            recursiveReversePrint(head);
            break;
        case 8:
            printf("Reversing list recursively\n");
            recursiveReverse(head);
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}