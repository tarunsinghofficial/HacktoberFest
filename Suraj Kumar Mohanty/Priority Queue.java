import java.util.*;
  
class Suraj1 
{
    public static void main(String args[])
    {
        Suraj1<Integer> pQueue = new Suraj1<Integer>();
        pQueue.add(10);
        pQueue.add(20);
        pQueue.add(15);
        System.out.println(pQueue.peek());
        System.out.println(pQueue.poll());
        System.out.println(pQueue.peek());
    }
}