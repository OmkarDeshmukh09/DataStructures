#include <stdio.h>
#include<stdlib.h>

#pragma pack (1)        
struct node
{
    int data;
    struct node *next ;
};

typedef struct node NODE;           // Added
typedef struct node * PNODE;        // Added
typedef struct node * *  PPNODE;    // Added

// Call by value

void Display ( PNODE first)
{}

int Count ( PNODE first)
{}


int main()
{
    PNODE head = NULL;

    Display(head);
    Count(head);

    return 0;

}