###################################################
#
#
#             Singly Leaner LinkList
#          DeleteAtPos Done in this code 
#
#
###################################################

# Class node Done
class Node:
    def __init__(self, value):
        self.data = value       
        self.next = None

    
class SinglyLL:
# Counstructor method Done(__init__)
    def __init__(self):
        self.first  = None
        self.iCount = 0

    def InsertFirst(self, no):

#       Newn-> object kelay (pointer nhiye)
        newn = Node(no)

#       SinglyLL is Empty
        if self.first == None:
            self.first = newn

#       SinglyLL has atleast one node
        else:
            newn.next = self.first
            self.first = newn

        self.iCount += 1
        
    def InsertLast(self, no):

#       Newn-> object kelay (pointer nhiye)
        newn = Node(no)

#       SinglyLL is Empty
        if self.first == None:
            self.first = newn

#       SinglyLL has atleast one node or multiple
        else:
            temp = self.first

            while(temp.next != None):
                temp = temp.next
            
            temp.next = newn

        self.iCount += 1

    def InsertAtPos(self, no, pos):

        if (pos < 1 or pos > (self.iCount + 1)):
            print("Invalid Position")
            return

        if(pos == 1):
            self.InsertFirst(no)
            return
        
        elif(pos == self.iCount+1):
            self.InsertLast(no)
            return

        else:
            newn = Node(no)

            temp = self.first

            for i in range(1,pos - 1):
                temp = temp.next
            
            newn.next = temp.next
            temp.next = newn

            self.iCount += 1

#   DeleteFirst Done 
    def DeleteFirst(self):
        
        if(self.first == None):
            return
        
        temp = self.first

        self.first = self.first.next

        del temp

        self.iCount -= 1

#       DeleteLast Done
    def DeleteLast(self):

#       SinglyLL is empty
        if(self.first == None):
            return
        
#       SinglyLL is atlest one ( Ek ch asel tr)
        if(self.first.next == None):    
            del self.first
            self.first = None
            self.iCount = 0
        else:
#           SinglyLL cointian more than one node
            temp = self.first

            while(temp.next.next != None):
                temp = temp.next
            
            del temp.next
            temp.next = None       

        self.iCount -= 1

#   DeleteAtPos Done in this code
    def DeleteAtPos(self, pos):
#       Filter
        if (pos < 1 or pos > (self.iCount)):
            print("Invalid Position")
            return

        if(pos == 1):
            self.DeleteFirst()
            return
        
        elif(pos == self.iCount):
            self.DeleteLast()
            return

        else:

            temp = self.first

            for i in range(1,pos - 1):
                temp = temp.next
            
            temp.next = temp.next.next
            
            self.iCount -= 1

#       Display Done 
    def Dispaly(self):
        temp = self.first

        while(temp != None):
            print("| ",temp.data," |->",end=" ")
            temp = temp.next

        print("None")

    def Count(self):
        return self.iCount

def main():
    sobj = SinglyLL()

    sobj.InsertFirst(101)
    sobj.InsertFirst(51)
    sobj.InsertFirst(21)
    sobj.InsertFirst(11)

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

    sobj.InsertLast(111)
    sobj.InsertLast(121)

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

    sobj.InsertAtPos(75, 4)

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

    sobj.DeleteFirst()
    sobj.DeleteFirst()

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

    sobj.DeleteLast()

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

    sobj.DeleteAtPos(3)

    print("Elements of linklist are : ")
    sobj.Dispaly()

    print("Number of Elements are : ",sobj.Count())

if __name__ == "__main__":
    main()