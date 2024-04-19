import java.util.Scanner;
class Sequential_search
{
	void seq(int sear, int a[])
	{
		int i;
		for(i=0;i<a.length;i++)
		{
			if(sear == a[i])
			{
				System.out.print("Found "+sear+".");
				break;
			}
		}
		if(i==a.length)
			System.out.print("Cannot Find "+sear+".");
	}
}
class Main
{
	public static void main(String ar[])
	{
		Scanner sc = new Scanner(System.in);
		int i,j,sear,t;

		System.out.print("Enter total number you want to search : ");
		t=sc.nextInt();

		int n[] = new int[t];
		for(i=0;i<n.length;i++)
		{
			System.out.print("Enter No "+(i+1)+": ");
			n[i]=sc.nextInt();
		}
		System.out.print("Enter the number to search : ");
		sear=sc.nextInt();
		
		Sequential_search s1 = new Sequential_search();
		s1.seq(sear,n);
	}
}