#include <stdio.h>

#pragma pack (1)        
struct node
{
    int data;
    struct node *next ;
};

typedef struct node NODE;

int main()
{
    struct node *head = NULL;       //Main LL chi starting point
    NODE obj ;

//  Created first NODE
    head = &obj ;                   //100 la point
    head -> data = 11 ;             // data la [11]     intilize
    head -> next = NULL;            // next la [NULL]   intilize
    
    return 0;
}