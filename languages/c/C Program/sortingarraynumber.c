#include<bits/stdc++.h>
using namespace std;

	// selection sort(O(n^2))

void ssort(int a[],int n)
{	
	for(int i=0;i<n-1;i++)
	{
		int p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[p])
			{
				p=j;	
			}	
		}
		swap(a[i],a[p]);
	}
}

void display(int a[],int n)
{	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}


int main()
{
	
  // array input
	
  int n;
	cout<<"enter the size of array :: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	ssort(a,n);
  display(a,n);
  return 0;
}
