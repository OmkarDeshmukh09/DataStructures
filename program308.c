#include <stdio.h>

#pragma pack (1)        
struct node
{
    int data;
    struct node *next ;
};

typedef struct node      NODE;      // Added
typedef struct node*     PNODE;     // Added
typedef struct node**    PPNODE;    // Added

int main()
{
    NODE obj ;
    PNODE ptr1 = NULL ;
    PPNODE ptr2 = NULL;

    ptr1 = &obj;
    ptr2 = &ptr1; 
    
    return 0;
}