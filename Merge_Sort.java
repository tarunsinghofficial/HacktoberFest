/Time Complexity O(nlgn) in all 3 cases/
import java.io.*;
class MergeSort
{
	public void merge(int arr[],int p,int q,int r)
	{
		int n1 = q-p+1;
		int n2 = r-q;
		int L[] = new int[n1+1];
		int R[] = new int[n2+1];
		L[n1] = 999999;
		R[n2] = 999999;
		for(int i=0;i<n1;i++)
			L[i] = arr[p+i];
		for(int i=0;i<n2;i++)
			R[i] = arr[q+1+i];
		int i=0,j=0;
		for(int k =p;k<=r;k++)
		{
			if(L[i]<=R[j])
			{
				arr[k]=L[i];
				i++;
			}
			else
			{
				arr[k]=R[j];
				j++;
			}
		}
	}
	public void sort(int arr[],int p,int r)
	{
		if(p<r)
		{
			int q= (p+r)/2;
			sort(arr,p,q);
			sort(arr,q+1,r);
			merge(arr,p,q,r);
		}
	}
}
class MergeSortDriver
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the number elements in the array: ");
		int n = Integer.parseInt(br.readLine());
		int arr[] = new int[n];
		System.out.println("Enter the number of elements of the array: ");
		String str = br.readLine();
		String ar[] = str.trim().split(" ");
		for(int i=0;i<n;i++)
			arr[i] = Integer.parseInt(ar[i]);
		MergeSort mergeSort = new MergeSort();
		mergeSort.sort(arr,0,n-1);
		System.out.println("The sorted array is: ");
		for(int i : arr)
			System.out.print(i+ " ");
	}
}
