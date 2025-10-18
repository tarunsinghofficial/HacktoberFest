public class ArrayElement
{
    public static void main(String[] args)
    {
        char[][] theArray = new char[][]{{'a', 'b', 'c'},
                                        {'d', 'e', 'f'},
                                        {'g', 'h', 'i'}};
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                 if (theArray[i][j] == 'e')
                 {
                    System.out.println(theArray[i][j]);
                    break;
                }
            }
        }
    }
}