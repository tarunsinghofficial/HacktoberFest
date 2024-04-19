Simple linear search and binary search

import java.util.*;
public class LSandBS{
	public int linearSearch(int[] arr,int x,int y){
		for(int m=0;m<x;m++){
			if(arr[m] == y){
				return m+1;
			}
		}
		return -1;
	}
	public void binarySearch(int []arr,int x,int key){
		int head = 0;
		// System.out.println(x);
		int tail = x-1;
		while(head <= tail)
			{
				int mid = (head+tail)/2;
				if(arr[mid] == key){
					System.out.println("The element is present at"+mid);
					return ;
				}
				if(arr[mid] > key){
					head = mid -1;
				}else{
					tail = mid +1;
				}
			}
		System.out.println("The element is absent in the array");
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements");
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i=0;i<n;i++){
			System.out.println("Enter the element");
			arr[i] = sc.nextInt();
		}
		System.out.println("Enter the element to be searched");
		int a = sc.nextInt();
		LSandBS obj = new LSandBS();
		obj.binarySearch(arr,n,a);
		// System.out.println("The element is found to be:"+obj.linearSearch(arr,n,a));
		// System.out.println("The element is found to be:"+obj.binarySearch(arr,n,a));

	}
}