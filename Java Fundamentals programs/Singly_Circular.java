import java.util.*;

class node{
    int data;
    node next;
};

class SinglyCL
{
    private int size;
    private node Head;
    private node Tail;

    public SinglyCL()
    {
        this.size = 0;
        this.Head = null;
        this.Tail = null;
    }

    public void Display()
    {
        node temp = Head;

        if((Head == null) && (Tail == null))
        {
            return;
        }
        else
        {
            do
            {
                System.out.print("|"+temp.data+"|->");
                temp = temp.next;
            }while(Tail.next != temp);

            System.out.print(" NULL\n");
        }
    }

    public int Count()
    {
        return this.size;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;

        if((Head == null) && (Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn.next = Head;
            Head = newn;
        }
        Tail.next = Head;
        size++;
    }

    public void InsertLast(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;

        if((Head == null)&&(Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            Tail = newn;
        }
        Tail.next = Head;
        size++;
    }

    public void DeleteFirst()
    {
        if((Head == null)&&(Tail == null))
        {
            return;
        }
        else
        {
            Head = Head.next;    
            System.gc();   
        }
        Tail.next = Head;
        size--;
    }

    public void DeleteLast()
    {
        node temp = Head;

        if((Head == null) && (Tail == null))
        {
            return;
        }
        else
        {
            while(temp.next.next != Tail.next)
            {
                temp = temp.next;
            }
            Tail = temp; 
            System.gc();
        }
        Tail.next = Head;
        size--;
    }

    public void InsertAtPos(int no, int ipos)
    {
        int i = 0;
        node temp = Head;

        if((ipos < 1) || (ipos > (size + 1)))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == (size + 1))
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node();
            newn.data = no;
            newn.next = null;

            for(i = 1; i < (ipos - 1); i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
            size++;
        }
        Tail.next = Head;
    }

    public void DeleteAtPos(int ipos)
    {
        int i = 0;
        node temp = Head;
        node Target = null;

        if((ipos < 1) || (ipos > size))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            for(i = 1; i < (ipos - 1); i++)
            {
                temp = temp.next;
            }
            Target = temp.next.next;
            temp.next = Target;
            System.gc();
            size--;
        }
        Tail.next = Head;
    }
}

public class SinglyCircular{
    public static void main(String args[])
    {
        int iRet = 0;
        int iValue = 1;
        int iChoice = 0;
        int ipos = 0;

        Scanner sc = new Scanner(System.in);
        SinglyCL sobj = new SinglyCL();

        while(iValue != 0)
        {
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Insert Element In The Linked List At First Position");
            System.out.println(" 2 : Insert Element In The Linked List At Last Position");
            System.out.println(" 3 : Insert Element In The Linked List At Desire Position");
            System.out.println(" 4 : Delete Element From The Linked List From First Position");
            System.out.println(" 5 : Delete Element From The Linked List From Last Position");
            System.out.println(" 6 : Delete Element From The Linked List From Desire Position");
            System.out.println(" 7 : Display Elements From The Linked List");
            System.out.println(" 8 : Count Elements From The Linked List");
            System.out.println(" 9 : Exit From The Application");
            System.out.println("-------------------------------------------------------------");
            System.out.println("Enter The Choice = ");
            iChoice = sc.nextInt();
    
            switch(iChoice)
            {
                case 1:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    sobj.InsertFirst(iValue);
                    break;
                case 2:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    sobj.InsertLast(iValue);
                    break;
                case 3:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    System.out.println("Enter The Position = ");
                    ipos = sc.nextInt(); 
                    sobj.InsertAtPos(iValue,ipos);
                    break;
                case 4:
                    sobj.DeleteFirst();
                    break;
                case 5:
                    sobj.DeleteLast();
                    break;
                case 6:
                    System.out.println("Enter The Position = ");
                    ipos = sc.nextInt();
                    sobj.DeleteAtPos(ipos);
                    break;
                case 7:
                    sobj.Display();
                    break;
                case 8:
                    iRet = sobj.Count();
                    System.out.println("The Elements From The Linked List Are = "+iRet);
                    break;
                case 9:
                    System.out.println("Thank You For Using Marvellous Linked List");
                    iValue = 0;
                    break;
                default:
                    System.out.println("Please Enter An Valid Choice !");
                    break;
            }
        }
        sc.close();
    }   
}
