#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}



int partition(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(a[j]<pivot)
		{
		
		i++;
		swap(&a[i],&a[j]);
	}
	}
	swap(&a[i+1],&a[high]);
	
	return i+1;
}

void quicksort(int a[],int low,int high){
	if(low<high){
		int pi=partition(a,low,high);
	
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}

int main(){
	int n;
	int i;
	cout<<"enter number of elements in array:"<<endl;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
		
	}
	quicksort(a,0,n-1);
	cout<<"sorted array:"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}