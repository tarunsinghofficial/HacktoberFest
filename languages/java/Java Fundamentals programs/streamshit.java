import java.util.*;
import java.util.stream.*;

public class streamshit
{
    public static void main(String[] args)
    {
        ArrayList<Integer> myList = new ArrayList<>();
        myList.add(47);
        myList.add(125);
        myList.add(91);
        myList.add(15);
        myList.add(5);
        myList.add(4);
        myList.add(7);

        Stream<Integer> myStream = myList.stream().filter((n) -> (n % 5) == 0);
        myStream.forEach((n) -> System.out.println(n));

    }
}