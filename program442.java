class node
{
    public int data;
    public node next;

    public node( int no)        // IMPORTANT
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL 
{
    public node first;
    public int iCount;

    public SinglyLL()       //if not written public defalut hoil
    {
        System.out.println("Object of SinglyLL get created");
        
        this.first=null;
        this.iCount= 0 ;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        //Changed Code
        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }
    
    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if (this.iCount == 1) 
        {
            newn = first;
        }
        else
        {
            temp = first;

            while (temp.next != null) 
            {
                temp =temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }
    
    public void InsertAtPos(int no , int pos)
    {}

    
    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int pos)
    {}

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while (temp != null) 
        {
            System.out.print(" | "+temp.data+" | -> ");
            temp = temp.next;    
        }
        System.out.println("null ");

    }

    public int Count()
    {
        return this.iCount ;
    }
}

class program442
{
    public static void main(String A[] ) 
    {
        int iRet = 0 ;
        SinglyLL obj = null;

        obj = new SinglyLL(); 

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();
        System.out.println("The numbers of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();
        System.out.println("The numbers of nodes are : "+iRet);
        
        //Free the memory is Important for memory deallocation
        obj = null;
        System.gc();
    
    }
    
}