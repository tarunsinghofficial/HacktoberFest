public class genericshit
{
    public static void main(String[] args)
    {
        Integer[] intArray = { 2, 4, 7, 39, 54 };
        Double[] doubleArray ={ 2.2, 4.4, 7.7, 3.9, 5.4 };
        Character[] charArray = {'S', 'H', 'A', 'W', 'T', 'Y'};

        printArray(charArray);
    }

    public static <T> void printArray(T[] inputArray)
    {
        for (T item : inputArray)
        {
            System.out.printf("%s ", item);
        }
    }
}