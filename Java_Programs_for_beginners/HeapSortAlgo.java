import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Dipyaman Saha (https://github.com/dipyamansaha) - HEAP SORT ALGORITHM -
 *     https://en.wikipedia.org/wiki/Heapsort
 */
public class HeapSortAlgo {
  static void HeapSort(int[] Arr) {
    int n = Arr.length;

    BuildMaxHeap(Arr);

    for (int i = (n - 1); i >= 0; i--) {
      int temp = Arr[0];
      Arr[0] = Arr[i];
      Arr[i] = temp;

      MaxHeapify(Arr, i, 0);
    }
  }

  static void MaxHeapify(int[] Arr, int n, int i) {
    int l = (2 * i + 1);
    int r = (2 * i + 2);

    int largest;

    if ((l < n) && (Arr[l] > Arr[i])) largest = l;
    else largest = i;

    if ((r < n) && (Arr[r] > Arr[largest])) largest = r;

    if (largest != i) {
      int temp = Arr[i];
      Arr[i] = Arr[largest];
      Arr[largest] = temp;

      MaxHeapify(Arr, n, largest);
    }
  }

  static void BuildMaxHeap(int[] Arr) {
    int n = Arr.length;

    for (int i = (n / 2 - 1); i >= 0; i--) MaxHeapify(Arr, n, i);
  }

  public static void main(String[] args) {
    System.out.println("HEAP SORT ALGORITHM\n");

    Scanner sc = new Scanner(System.in);

    System.out.print("How many elements do you wanna insert? ");
    int n = sc.nextInt();

    int[] Arr = new int[n];

    System.out.println("Enter the elements: ");
    for (int i = 0; i < n; i++) {
      Arr[i] = sc.nextInt();
    }

    System.out.println("The entered array: " + Arrays.toString(Arr));

    HeapSort(Arr);
    System.out.println("The sorted array: " + Arrays.toString(Arr));
  }
}
