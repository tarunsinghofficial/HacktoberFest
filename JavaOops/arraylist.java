import java.util.*;
public class arraylist
{
	public static void main(String[] args) {
		int[] arr = {1,2,3,4,5};
		int[] arr1 = {3,4,5,6};
		int[] arr3 = new int[arr.length+arr1.length];
		ArrayList<Integer> a = new ArrayList<Integer>();
		for(int i=0;i<arr.length;i++){
			arr3[i] = arr[i];
		    a.add(arr[i]);
		}
		for(int i=0;i<arr1.length;i++){
			arr3[arr.length+i] = arr1[i];
		    a.add(arr1[i]);
		}
		int n = a.size();
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){
				if(arr3[j]>arr3[j+1]){
					int temp = arr3[j];
					arr3[j] = arr3[j+1];
					arr3[j+1] = temp;
				}
			}
		}
		for(int i=0;i<arr3.length;i++){
			System.out.println(arr3[i]);
		}
		Collections.sort(a);
		System.out.println(a);
	}
}