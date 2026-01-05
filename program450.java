//Doubly Linear
class node {
    public int data;
    public node next;
    public node prev;

    public node(int no) {
        this.data = no;
        this.next = null;
        this.prev = null;
    }

}

class DoublyLL {
    private node first;

    private int iCount;

    DoublyLL() {
        System.out.println("Object of SinglyCL gets Created");
        this.first = null;

        this.iCount = 0;

    }

    public void InsertFirst(int no)
    {   
        node newn=null;
        newn=new node(no);

        if (this.first==null)
        {
            this.first=newn;  
        }
        else
        {
            newn.next=this.first;
            this.first=newn;
            newn.next.prev=newn;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {   
        node newn=null;
        node temp=null;
        newn=new node(no);

        if (first == null)
        {
            this.first=newn;    
        }
        else
        {   
            temp=first;

            while (temp.next.next!=null)
            {
                temp=temp.next;    
            }
            temp.next.next=newn;
            newn.prev=temp.next;
        }
        this.iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {   
        node newn=null;
        node temp=null;
        int i = 0;
        if (pos<1 || pos>iCount+1)
        {
            System.out.println("Invalid Position");
            return;    
        }

        if (pos==1)
        {
            InsertFirst(no);    
        }
        else if (pos==iCount+1)
        {
            InsertLast(no);    
        }
        else
        {
            newn=new node(no);
            temp=first;
            for (i = 1; i < pos-1; i++)
            {
                temp=temp.next;
            }
            newn.next=temp.next;
            newn.prev=temp;
            temp.next=newn;
            newn.next.prev=newn;
            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        if (first == null)
        {
            System.out.println("Linked List is Already Empty");
            return;    
        }

        if (first.next==null) 
        {
            this.first=null;    
        }
        else
        {
            this.first=first.next;
            first.prev=null;            
        }
        System.gc();
        iCount--;
    }

    public void DeleteLast() 
    {   
        node temp=null;
        if (first == null)
            {
                System.out.println("Linked List is Already Empty");
                return;    
            }
    
            if (first.next==null) 
            {
                this.first=null;    
            }
            else
            {
                temp=first;

                while (temp.next.next!=null)
                {
                    temp=temp.next;    
                }
                temp.next=null;
                System.gc();
                this.iCount--;

            }
    }

    public void DeleteAtPos(int pos)
    {
        node temp=null;
        int i = 0;
        if (pos<1 || pos>iCount+1)
        {
            System.out.println("Invalid Position");
            return;    
        }

        if (pos==1)
        {
            DeleteFirst();    
        }
        else if (pos==iCount)
        {
            DeleteLast();    
        }
        else
        {   
            temp=first;
            for ( i = 1; i < pos-1; i++)
            {
                temp=temp.next;    
            }
            temp.next=temp.next.next;
            temp.next.prev=temp;
            System.gc();
            this.iCount--;
        }
    }

    public void Display() 
    {
        node temp=null;
        temp=first;
        while (temp!=null)
        {   
            System.out.print("|"+temp.data+"|->");
            temp=temp.next;    
        }
        System.out.println("NULL");
    }

    public int Count() {
        return iCount;
    }

}

public class program450 {
    public static void main(String[] A) {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.DeleteFirst();
        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.DeleteLast();
        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.InsertAtPos(104, 4);
        obj.InsertAtPos(105, 5);
        obj.InsertAtPos(106, 6);
        obj.InsertAtPos(107, 7);
        obj.InsertAtPos(108, 8);
        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.DeleteAtPos(4);
        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        // Important For Memory Deallocation
        obj = null;
        System.gc();

    }
}