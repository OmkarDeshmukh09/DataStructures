//Singly Circular
class node {
    public int data;
    public node next;

    public node(int no) {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL {
    private node first;
    private node last;
    private int iCount;

    SinglyCL() {
        System.out.println("Object of SinglyCL gets Created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no) {
        node newn = null;
        newn = new node(no);

        if (this.first == null && this.last == null) {
            this.first = newn;
            this.last = newn;
            newn.next = this.last;

        } else {
            newn.next = first;
            this.first = newn;
            this.last.next = this.first;

        }
        this.iCount++;

    }

    public void InsertLast(int no) {
        node newn = null;
        newn = new node(no);
        node temp;

        if (this.first == null && this.last == null) {
            this.first = newn;
            this.last = newn;
            newn.next = this.last;
        } else {
            this.last.next = newn;
            this.last = newn;
            newn.next = this.first;

        }
        this.iCount++;
    }

    public void InsertAtPos(int no, int pos) {
        node newn;
        node temp;
        int i = 0;
        if (pos < 1 || pos > iCount + 1) {
            System.out.println("Invalid Position");
            return;
        }
        if (pos == 1) {
            InsertFirst(no);
        } else if (pos == iCount + 1) {
            InsertLast(no);
        } else {
            temp = this.first;
            newn = new node(no);
            for (i = 1; i < pos - 1; i++) {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;

        }
    }

    public void DeleteFirst() {
        if (this.first == null && this.last == null) {
            System.out.println("Linked List Is already Empty");
            return;
        } else if (this.first == this.last) {
            this.first = null;
            this.last = null;

        } else {
            this.first = first.next;
            this.last.next = this.first;
        }
        System.gc();
        iCount--;
    }

    public void DeleteLast() {
        node temp = null;
        if (this.first == null && this.last == null) {
            System.out.println("Linked List Is Already Empty");
            return;
        } else if (this.first == this.last) {
            this.first = null;
            this.last = null;
        } else {
            temp = first;
            while (temp.next != last.next) {
                temp = temp.next;
            }
            temp.next = first;
            last = temp;
        }
        System.gc();
        iCount--;
    }

    public void DeleteAtPos(int pos) {

        node temp;
        int i = 0;
        if (pos < 1 || pos > iCount) {
            System.out.println("Invalid Position");
            return;
        }

        if (pos == 1) {
            DeleteFirst();
        } else if (pos == iCount) {
            DeleteLast();
        } else {
            temp = first;
            for (i = 1; i < pos - 1; i++) {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            System.gc();
            iCount--;
        }
    }

    public void Display() {
        node temp = null;
        temp = first;
        for (int i = 1; i <= iCount; i++) {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    public int Count() {
        return iCount;
    }

}

public class program447 {
    public static void main(String[] A) {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

        obj.InsertAtPos(1, 1);
        obj.InsertAtPos(2, 2);
        obj.InsertAtPos(3, 3);
        obj.InsertAtPos(4, 4);
        obj.InsertAtPos(5, 5);
        obj.InsertAtPos(6, 6);
        obj.InsertAtPos(7, 7);
        obj.InsertAtPos(8, 8);
        obj.InsertAtPos(9, 9);
        obj.InsertAtPos(10, 10);
        obj.InsertAtPos(11, 11);
        obj.InsertAtPos(12, 12);
        obj.InsertAtPos(13, 13);
        obj.InsertAtPos(14, 14);
        obj.InsertAtPos(15, 15);
        obj.InsertAtPos(16, 16);
        obj.InsertAtPos(17, 17);
        obj.InsertAtPos(18, 18);
        obj.InsertAtPos(19, 19);
        obj.InsertAtPos(20, 20);
       

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