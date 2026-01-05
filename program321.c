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
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));     //memory allocation

    newn -> data = no;                      //intilization
    newn -> next = NULL;                    //intilization (mula cha haat khaali kela)

    if (*first ==NULL)                      /* LINKLIST is empty */
    {
        (*first) = newn;                      //
    }
    else                                    /* LINKLIST cointains atleast 1 node */
    {
        temp = *first;
        while (temp -> next != NULL)
        {
            temp = temp -> next ;
        }
        temp -> next = newn ;
    }
}

void Display (PNODE first)
{
    while (first != NULL)
    {
        printf(" | %d | ->",first -> data); //Beautification
        first = first -> next;
    }
    printf(" NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first -> next ;
    }
    return iCount;
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if ((*first) == NULL)                   // Case 1
    {
        return ;
    }
    else if ((*first) -> next == NULL)      // Case 2
    {
        free(*first);
        *first = NULL;   
    }
    else
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);
    }   
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL; 
    if ((*first) == NULL)                   // Case 1
    {
        return ;
    }
    else if ((*first) -> next == NULL)      // Case 2
    {
        free(*first);
        *first = NULL;   
    }
    else
    {
        
    }   
}

int main()
{
    PNODE head = NULL;
    int iRet = 0 ;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d \n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d \n",iRet);

    return 0 ;
} 