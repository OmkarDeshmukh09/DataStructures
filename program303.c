#include <stdio.h>

struct node
{
    int data;
    struct node *next ;
};

int main()
{
    struct node obj;    //memory Initilazition done one Node created

    printf("%ld",sizeof(obj));

    return 0;
}