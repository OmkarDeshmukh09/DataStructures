//Doubly Circular
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

class DoublyCL {
    private node first;
    private node last;
    private int iCount;

    DoublyCL() {
        System.out.println("Object of DoublyCL gets Created");
        this.first = null;
        this.last = null;
        this.iCount = 0;

    }

    public void InsertFirst(int no) {
        node newn = null;
        newn = new node(no);

        if (first == null && last == null)// When Linked List is Empty
        {
            first = newn;
            last = newn;
            first.prev = last;

        } else {
            newn.next = first;
            newn.prev = last;
            first = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertLast(int no) {
        node newn = null;
        newn = new node(no);

        if (first == null && last == null)// When Linked List is Empty
        {
            first = newn;
            last = newn;
            first.prev = last;
        } else {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertAtPos(int no, int pos) {
        int i = 0;
        node newn = null;
        node temp = null;
        if (pos < 1 || pos > iCount + 1) {
            System.out.println("Invalid Position");
            return;
        }

        if (pos == 1) {
            InsertFirst(no);
        } else if (pos == iCount + 1) {
            InsertLast(no);
        } else {
            newn = new node(no);
            temp = first;
            for (i = 1; i < pos - 1; i++) {
                temp = temp.next;
            }
            newn.next = temp.next;
            newn.prev = temp;
            temp.next = newn;
            newn.next.prev = temp;
            iCount++;

        }
    }

    public void DeleteFirst() {
        if (first == null && last == null) {
            System.out.println("Linked list is already empty");
            return;
        } else if (first == last)// if it have a one element
        {
            first = null;
            last = null;
        } else {
            first = first.next;
            first.prev = last;
        }
        iCount--;
        System.gc();
    }

    public void DeleteLast() {
        if (first == null && last == null) {
            System.out.println("Linked list is already empty");
            return;
        } else if (first == last)// if it have a one element
        {
            first = null;
            last = null;
        } else {
            last = last.prev;
            last.next = first;
        }
        iCount--;
        System.gc();
    }

    public void DeleteAtPos(int pos) {
        node temp = null;
        if (pos < 1 || pos > iCount + 1) {
            System.out.println("Invalid Position");
            return;
        }

        if (pos == 1) {
            DeleteFirst();
        } else if (pos == iCount) {
            DeleteLast();
        } else {
            temp = first;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
            iCount--;
            System.gc();
        }
    }

    public void Display() {
        int i = 0;
        node temp = null;
        temp = first;

        for (i = 1; i <= iCount; i++) {
            System.out.print("|" + temp.data + "|=>");
            temp = temp.next;
        }
        System.out.println("");
    }

    public int Count() {
        return iCount;
    }

}

public class program449 {
    public static void main(String[] A) {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

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

        obj.InsertAtPos(105, 4);
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