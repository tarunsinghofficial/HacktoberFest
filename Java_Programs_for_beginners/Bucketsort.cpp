import java.util.*;  
public class BucketSortExample1   
{  
//user-defined method to sort array  
private static void binSort(int[] array, int bucketSize)  
{  
//creating a list of buckets for storing lists  
List<Integer>[] buckets = new List[bktSize];  
// Linked list with each bucket array index  
// as there may be hash collision   
for(int i = 0; i < bktSize; i++)  
{  
buckets[i] = new LinkedList<>();  
}  
//calculate the hash and assigns elements to the proper bucket  
for(int num : array)  
{  
buckets[hash(num, bktSize)].add(num);  
}  
//iterate over the buckets and sorts the elements  
for(List<Integer> bucket : buckets)  
{  
//sorts the bucket      
Collections.sort(bucket);  
}  
int index = 0;  
//gethered the buckets after sorting  
for(List<Integer> bucket : buckets)  
{  
for(int num : bucket)  
{  
array[index++] = num;  
}  
}  
}  
//distributing elements   
private static int hash(int num, int bucketSize)  
{  
return num/bucketSize;  
}  
public static void main(String args[])   
{  
//array to be sort      
int[] array = {22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14, 55, 0, 12, 55};  
System.out.println("Unsorted Array: " + Arrays.toString(array));  
//calling the user-defined method to sort the array  
binSort(array, 10);  
System.out.println("Sorted Array: " + Arrays.toString(array));  
}  
}  
