class node
{
    public int data;
    public node next;
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
    {}
    
    public void InsertLast(int no)
    {}
    
    public void InsertAtPos(int no , int pos)
    {}

    
    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int pos)
    {}

    public void Display()
    {}

    public int Count()
    {
        return this.iCount ;
    }


}

class program439
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
    
    }
    
}