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
    NODE obj;

    obj.data = 11;      //Initilize zale  data[11]
    obj.next = NULL;    //Initilize zale  next[NULL]

    return 0;
}