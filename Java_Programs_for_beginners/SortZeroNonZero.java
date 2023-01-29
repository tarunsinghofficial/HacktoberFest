import java.io.*;
class SortZeroNonZero
{
void endZeroes(int arr[]) 
{ 
int i,c=0;
int arrnew[]=new int[arr.length];
for(i=0;i<arr.length;i++)
{
arrnew[i]=arr[i];
}
for(i=0;i<arrnew.length;i++)
{
if(arrnew[i]!=0) 
arrnew[c++]=arrnew[i];
}
while(c<arrnew.length)
{
arrnew[c++]=0; 
}
System.out.println("\nThe sorted array with the zeroes at the end is as follows: ");
for(i=0;i<arrnew.length;i++)
{
System.out.println(arrnew[i]);
}
}
void frontZeroes(int arr[])
{
int i,c=arr.length-1;
int arrnew[]=new int[arr.length];
for(i=0;i<arr.length;i++)
{
arrnew[i]=arr[i];
}
for(i=arrnew.length-1;i>=0;i--)
{
if(arrnew[i]!=0)
arrnew[c--]=arrnew[i];
}
while(c>=0)
{
arrnew[c--]=0;
}
System.out.println("\nThe sorted array with the zeroes at the beginning is as follows: ");
for(i=0;i<arrnew.length;i++)
{
System.out.println(arrnew[i]);
}
}
public static void main(String args[]) throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int n;
System.out.println("\nEnter the number of elements in the array: ");
n=Integer.parseInt(br.readLine());
int arr[]=new int[n];
System.out.println("\nEnter the elements of the array (please enter both zero and non-zero integers): ");
int i;
for(i=0;i<n;i++)
{
arr[i]=Integer.parseInt(br.readLine());
}
SortZeroNonZero ob=new SortZeroNonZero();
ob.endZeroes(arr);
ob.frontZeroes(arr);
}
}