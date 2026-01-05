#include <stdio.h>

#pragma pack (1)        // Added for removing padding
struct node
{
    int data;
    struct node *next ;
};

int main()
{
    struct node obj;

    printf("%ld",sizeof(obj));

    return 0;
}