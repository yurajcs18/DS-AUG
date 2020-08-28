#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;        
    struct node *next; 
}*head;


void createList(int n);
void deleteFirstNode();
void displayList();
deleteLastNode();
 deleteFirstByKey(key);



int main()
{
    int n, choice, key;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nPress 1 to delete first node:\n Press 2 to Delete last node: \n Press 3 to delete specific node by key :\n ");
    scanf("%d", &choice);
    switch(choice){
        case 1 : deleteFirstNode(); break ;
        case 2 : deleteLastNode(); break ;
        case 3 :  printf("\nEnter element to delete with key: ");
                  scanf("%d", &key);
                  deleteFirstByKey(key);break;
                 }
    

    printf("\nData in the list \n");
    displayList();

    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode; 
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;               
        }
    }
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void deleteFirstByKey(int key)
{
    struct node *prev, *cur;
    while (head != NULL && head->data == key)
    {
        prev = head;
        head = head->next;
        free(prev);
        return;
    }

    prev = NULL;
    cur  = head;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            if (prev != NULL) 
                prev->next = cur->next;
            free(cur); 
            return;
        } 

        prev = cur;
        cur = cur->next;
    }
}