package Array;

import java.util.Arrays;

public class MergeWithoutExtraSpace {

	public static void main(String[] args) {
		int[] a1 = {10, 27, 38, 43, 82};
        int[] a2 = {3, 9};
        mergeArrays(a1, a2);
        
        System.out.print("First Array: ");
        for (int i = 0; i < a1.length; i++) {
            System.out.print(a1[i] + " ");
        }

        System.out.println();

        System.out.print("Second Array: ");
        for (int i = 0; i < a2.length; i++) {
            System.out.print(a2[i] + " ");
        }
	}
	public static void mergeArrays(int arr1[], int arr2[])
	{
		int n = arr1.length;
		int m = arr2.length;
		
		int gap = n+m;
		int i,j;
		for(gap = nextGap(gap);gap>0;gap = nextGap(gap))
		{
			for(i=0;i+gap<n;i++)
				if(arr1[i]>arr1[i+gap])
					swap(arr1[i],arr1[i+gap]);
			
			for(j = gap>n ? gap-n : 0; i<n && j<m;i++,j++ )
				if(arr1[i]>arr2[j])	
					swap(arr1[i],arr2[j]);
			
			if(j<m)
			{
				for(j=0;j+gap<m;j++)
				{
					if(arr2[j]> arr2[j+gap])
					{
						swap(arr2[j], arr2[j+gap]);
					}
				}
			}
		}
	}
	private static void swap(int i, int j)
	{
		int temp = i;
		i = j;
		j = temp;
	}
	private static int nextGap(int gap)
	{
		if(gap<=1)
			return 0;
		return (gap/2)+(gap%2);
	}
}
