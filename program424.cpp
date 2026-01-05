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
        
        //UPdated lines by reducing lines
        newn->next = first;     
        first = newn;           
        
        iCount++;
    }
    
    void InsertLast(int no)
    {
        PNODE newn = NULL;      //Pointer banavala
        PNODE temp = NULL;      //Xerox lagnar to TRAVERSE

        newn =new NODE;         //Creaate zala

        newn->data=no;
        newn->next= NULL;
        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while (temp->next != NULL)      //type 2 loop
            {
                temp = temp->next;
            }

            temp->next = newn;
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

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";
        
    return 0 ;
}