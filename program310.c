#include <stdio.h>
#include<stdlib.h>

#pragma pack (1)        

typedef struct node     //new type of typedef technique
{
    int data;
    struct node *next ;
}NODE, *PNODE ,**PPNODE ;    

int main()
{
    PNODE ptr = NULL;

    ptr =(PNODE) malloc (sizeof(NODE));

    //USe the Node 
    
    free(ptr);

    return 0;

}