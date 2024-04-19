
import java.util.*;
public class Collection
{
    int arr[];
    int len;
    Collection()
    {
        len=100;
        arr=new int[len];
    }
    Collection(int l)
    {
        len=l;
        arr=new int[len];
    }
    void imparr()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the elements in the array");
        for(int i=0;i<len;i++)
        {
            arr[i]=in.nextInt();
        }
    }
    Collection common(Collection b)
    {
        Collection c=new Collection();
        for(int i=0;i<this.len;i++)
        {
            c.arr[i]=this.arr[i];
        }
        for(int i=0;i<b.len;i++)
        {
            c.arr[i+this.len]=b.arr[i];
        }
        return c;
    }
    void arrange()
    {
        int temp;
        for(int i=0;i<len-1;i++)
        {
            for(int j=1;j<len;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
    void display()
    {
        for(int i=0;i<len;i++)
        {
            if(arr[i]!=0)
            System.out.println(arr[i]);
        }
    }
    public static void main()
    {
        int len;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the length of array 1");
        len=in.nextInt();
        Collection a=new Collection(len);
       
        a.imparr();
        System.out.println("Enter the length of array 2");
        len=in.nextInt();
        Collection b=new Collection(len);
        
        b.imparr();
        Collection c=new Collection();
        c=a.common(b);
        c.arrange();
        System.out.println("First Array");
        a.display();
        System.out.println("Second Array");
        b.display();
        System.out.println("Merged Array");
        c.display();
    }
}
        
        
