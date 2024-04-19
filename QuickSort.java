import java.util.Scanner;

public class QuickSort {
	public static int[] acceptArray() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the Size of array: ");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter the elements of array: ");
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();

		}

		return arr;


	}
	public static void printArray(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");

		}

	}
	public static int partitionFunc(int inp[],int startIndex, int endIndex){ 
		int pivot = inp[startIndex];
		int count = 0;
		for(int i=startIndex+1;i<=endIndex;i++) {
			if(inp[i]<=pivot) {
				count++;
			}
		}
		int pivotIndex = startIndex+count;
		inp[startIndex] = inp[pivotIndex];
		inp[pivotIndex] = pivot;
		int i=startIndex, j = endIndex;
		while(i<j) {
			while(i<=endIndex && inp[i]<=pivot) {
				i++;
			}
			while(inp[j]>pivot) {
				j--;
			}
			if(i<=j) {
				int temp = inp[i];
				inp[i] = inp[j];
				inp[j] = temp;
				i++;
				j--;
			}
		}
		return pivotIndex;
	}
	public static void quickSort(int inp[], int startIndex, int endIndex) {
		if(startIndex>=endIndex) {
			return;
		}
		int partIndex = partitionFunc(inp, startIndex, endIndex);
		quickSort(inp, startIndex, partIndex-1);
		quickSort(inp, partIndex+1, endIndex);
	}
	public static void quickSort(int inp[]) {
		quickSort(inp, 0, inp.length-1);

	}
	public static void main(String[] args) {
		int arr[] = acceptArray();
		printArray(arr);
		quickSort(arr);
		System.out.println("\nThe Sorted array is: ");
		for(int i : arr) {
			System.out.print(i+" ");
		}
		System.out.println();

	}
}
