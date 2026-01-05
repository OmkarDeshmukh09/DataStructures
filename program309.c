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

int main()
{
    PNODE ptr = NULL;
//  ptr = typecast(ptr1)  *           12byte
    ptr =   (PNODE)     malloc (sizeof(NODE));

    //USe the Node 
    
    free(ptr);

    return 0;

}