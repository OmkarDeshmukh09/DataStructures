#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node     NODE;
typedef struct node*    PNODE;
typedef struct node**   PPNODE;

class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout<<"Object of SinglyLL gets Created.\n";
            first = NULL;
            iCount = 0 ;
        }
    
    void InsertFirst(int no)
    {
        PNODE newn = NULL;      //Pointer banavala

        newn =new NODE;         //Creaate zala

        newn->data=no;
        newn->next= NULL;
        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;     //Rigth side connect zali
            first = newn;           //insert zala ani conntion zale
        }
        iCount++;
    }
    
    void InsertLast(int no)
    {
        PNODE newn = NULL;      //Pointer banavala

        newn =new NODE;         //Creaate zala

        newn->data=no;
        newn->next= NULL;
        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            
        }
        iCount++;
    }

    void InsertAtPos(int no, int pos)
    {}

    void DeleteFirst()
    {}

    void DeleteLast()
    {}

    void DeleteAtPos()
    {}
    
    void Display()
    {
        PNODE temp = NULL;

        temp = first;       //Xerox keli first

        while (temp != NULL)
        {
            cout<<" | "<<temp->data<<" | -> ";
            temp = temp->next;
        }
        cout<<" NULL\n";
    }

    int Count()
    {
        return iCount;
    }
};


int main()
{
    SinglyLL obj;

    int iRet = 0 ;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";


    return 0 ;
}