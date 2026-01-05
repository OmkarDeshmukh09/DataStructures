
//                                  USE OF (THIS->)

#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node     NODE;
typedef struct node*    PNODE;
//typedef struct node**   PPNODE; we dont use in cpp

class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout<<"Object of SinglyLL gets Created.\n";
            this->first = NULL;
            this->iCount = 0 ;
        }
    
    void InsertFirst(int no)
    {
        PNODE newn = NULL;      //Pointer banavala

        newn =new NODE;         //Creaate zala

        newn->data=no;
        newn->next= NULL;
        
        //UPdated lines by reducing lines
        newn->next = this->first;     
        this->first = newn;           
        
        this->iCount++;
    }
    
    void InsertLast(int no)
    {
        PNODE newn = NULL;      //Pointer banavala
        PNODE temp = NULL;      //Xerox lagnar to TRAVERSE

        newn =new NODE;         //Creaate zala

        newn->data=no;
        newn->next= NULL;
        if (this->iCount == 0)        //Updated
        {
            this->first = newn;
        }
        else
        {
            temp = this->first;

            while (temp->next != NULL)      //type 2 loop
            {
                temp = temp->next;
            }

            temp->next = newn;
        }
        this->iCount++;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;

        if (this->first == NULL)
        {
            return;
        }
        else if (this->first->next == NULL)       //elseif (this->iCount==1)
        {
            delete this->first;
            this->first = NULL;
        }
        else
        {
            temp = this->first;
            
            this->first = this->first->next;
            delete temp;
        }      

        this->iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if (this->first == NULL)
        {
            return;
        }
        else if (this->first->next == NULL)       //elseif (this->iCount==1)
        {
            delete this->first;
            this->first = NULL;
        }
        else
        {
            temp = this->first;
        
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp ->next = NULL;
        }   

        this->iCount--;
    }
    
    void Display()
    {
        PNODE temp = NULL;
        int iCnt = 0 ;

        temp = this->first;       //Xerox keli first chi temp mahun

        //while loop to for loop Change
        for (iCnt = 1 ;iCnt <= this->iCount ; iCnt++)
        {
            cout<<" | "<<temp->data<<" | -> ";
            temp = temp->next;
        }
        cout<<" NULL\n";
    }

    int Count()
    {
        return this->iCount;
    }

    void InsertAtPos(int no, int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        int iCnt = 0;

        if (pos < 1 || pos < this->iCount+1)
        {
            cout<<"Invalid Position";
            return;
        }

        if (pos == 1)
        {
            this->InsertFirst(no);
        }
        else if (pos == (this->iCount +1))
        {
            this->InsertLast(no);
        }
        else
        {
            newn = new NODE;

            newn->data =no;
            newn->next = NULL;
            
            temp = this->first;

            for ( iCnt = 1; iCnt < pos - 1 ; iCnt++)
            {
                temp =temp->next;
            }
              
            newn->next = temp->next;
            temp->next = newn;

            this->iCount++;
            
        }
    }
    
    
    void DeleteAtPos(int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        PNODE target = NULL;

        int iCnt = 0;

        if (pos < 1 || pos > this->iCount)
        {
            cout<<"Invalid Position";
            return;
        }

        if (pos == 1)
        {
            this->DeleteFirst();
        }
        else if (pos == this->iCount)
        {
            this->DeleteLast();
        }
        else
        {
            temp = this->first;

            newn = new NODE;

            for ( iCnt = 1; iCnt < pos - 1 ; iCnt++)
            {
                temp->next = newn;    
            }
            target = temp->next;
            
            temp->next = target->next;
            delete target;

            this->iCount--;
        }
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

    obj.DeleteFirst();
    
    obj.Display();

    //  obj.first = NULL; RISKY SYNTAX
    //  obj.iCount = 0;

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";

    obj.DeleteLast();
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes Are : "<<iRet<<"\n";

    return 0 ;
}