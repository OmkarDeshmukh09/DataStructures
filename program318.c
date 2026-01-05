#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int data ;
    struct node *next ;
};

typedef struct node NODE ;
typedef struct node * PNODE;        //typedef NODE* PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;      //for malloc return value catch

    newn = (PNODE)malloc(sizeof(NODE));     //memory allocation

    newn -> data = no;                      //intilization
    newn -> next = NULL;                    //intilization

    if (*first ==NULL)                      /* LINKLIST is empty */
    {
        (*first) = newn;                      //
    }
    else                                    /* LINKLIST cointains atleast 1 node */
    {
        newn -> next = (*first) ;
        (*first) = newn;
    }
}

void InsertLast(PPNODE first , int no)
{
    PNODE newn = NULL;      //for malloc return value catch

    newn = (PNODE)malloc(sizeof(NODE));     //memory allocation

    newn -> data = no;                      //intilization
    newn -> next = NULL;                    //intilization

    if (*first ==NULL)                      /* LINKLIST is empty */
    {
        (*first) = newn;                      //
    }
    else                                    /* LINKLIST cointains atleast 1 node */
    {

    }
}

void Display (PNODE first)
{
    while (first != NULL)
    {
        printf(" | %d | ->",first -> data); //Beautification
        first = first -> next;
    }
    printf(" NULL","\n");
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    return 0 ;
}