#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node     NODE;
typedef struct node*    PNODE;
typedef struct node**   PPNODE;

void InsertFirst(PPNODE first , PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;


    if ((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last  = newn;
        
    }
    else
    {
        newn->next = *first;
        *first = newn ;
    }

    (*last)->next =*first;
}

void InsertLast(PPNODE first , PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;


    if ((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last  = newn;
        
    }
    else
    {
        (*last)->next =newn;
        *last =newn;
    }

    (*last)->next =*first;
}

void  DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if ((*first == NULL) && (*last == NULL))        //Case 1 empty
    {
        return;
    }
    else if (*first == *last)                       //Case 2 one node
    {
        free(*first);

        *first = NULL;
        *last = NULL ;
    }
    else                                            //Case 3
    {
        temp = *first;

        *first = (*first)->next;

        free(temp);

        (*last)->next = *first ;
    }    
}

void  DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if ((*first == NULL) && (*last == NULL))        //Case 1 empty
    {
        return;
    }
    else if (*first == *last)                       //Case 2 one node
    {
        free(*first);

        *first = NULL;
        *last = NULL ;
    }
    else                                            //Case 3
    {
        temp = *first;

        while (temp ->next != *last)
        {
            temp = temp->next;
        }
        free(*last);
        *last = temp ;

        (*last)-> next =*first;
    }
}

void Display(PNODE first, PNODE last)
{
    do
    {
        printf(" | %d | -> ",first->data);
        first= first->next ;

    } while (first != last->next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        printf(" | %d | -> ",first->data);
        first= first->next ;

    } while (first != last->next);

    printf("\n");
    return iCount ;
}

void InsertAtPos(PPNODE first , PPNODE last, int no, int pos)
{
    int iCount = 0;
    int i = 0 ;
    PNODE temp = NULL;
    PNODE newn = NULL;  

    iCount = Count(first,last);
    
    if(pos < 0 || iCount + 1 > pos )            //Filter
    {
        printf("Invalid Input");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(first, last,no);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;
        
        newn =(PNODE)malloc(sizeof(NODE));

        newn->data = no; 
        newn->next = NULL;

        for ( i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next=newn;
    }    
}

void  DeleteAtPos(PPNODE first, PPNODE last , int pos)
{
    
    int iCount = 0;

    iSize = Count(first,last)
    
    if (pos < 0 || iSize + 1 > pos )            //Filter
    {
        printf("Invalid Input");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;
        
        newn =(PNODE)malloc(sizeof(NODE));

        newn->data = no; 
        newn->next = NULL;

        for ( iCnt = 1; iCnt < iSize; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp;

    }    
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;      // ( @ ) means new

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,51);
    
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Total number of Nodes : %d",iRet);

    DeleteFirst(&head,&tail);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Total number of Nodes : %d",iRet);

    DeleteLast(&head,&tail);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Total number of Nodes : %d",iRet);

    InsertAtPos(&head,&tail,71,3);
    
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Total number of Nodes : %d",iRet);

    return 0 ;
}