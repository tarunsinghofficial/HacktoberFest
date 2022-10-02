public class Bubblesort
{
   public static void main(String[] args)
   {
      int n = 10, i, j, x;
      int[] array = new int[n];
      Scanner s = new Scanner(System.in);

      System.out.print("Enter no. of elements in random order:");
      for(i=0; i<n; i++)
      {
         array[i] = s.nextInt();
      }

      for(i=0; i<(n-1); i++)
      {
         for(j=0; j<(n-i-1); j++)
         {
            if(array[j]>array[j+1])
            {
               x = array[j];
               array[j] = array[j+1];
               array[j+1] = x;
            }
         }
      }

      System.out.println("\nThe new sorted array is:");
      for(i=0; i<n; i++)
         System.out.print(array[i]+ " ");
   }
}
