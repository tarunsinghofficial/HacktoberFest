#include <iostream>
using namespace std;

void print(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int * mergeSort(int arr[],int i,int j){
	int *temp = new int[50];
	if(i==j){
		// cout<<"base: "<<arr[i]<<endl;
		temp[0] = arr[i];
		return temp;
	}
	
	int low = i;
	int high = j;
	int mid = (low + high)/2;

	int m = mid - low + 1;
	int n = high - mid;
	// cout<<m<<", "<<n<<endl;
	int *left = mergeSort(arr,low,mid);
	int *right = mergeSort(arr,mid+1,high);

	int itr_sol = 0;
	int limit = m+n;
	// cout<<"Limit: "<<limit<<endl;
	int itr_left=0;
	int itr_right=0;
	while(itr_left<m and itr_right<n){
		if(left[itr_left]<=right[itr_right])
			temp[itr_sol++] = left[itr_left++];
		else
			temp[itr_sol++] = right[itr_right++];
	}

	while(itr_left<m)
	{
		temp[itr_sol++] = left[itr_left++];
	}

	while(itr_right<m)
	{
			temp[itr_sol++] = right[itr_right++];
	}

	// print(temp,m+n);
	// cout<<endl;
	return temp;
}
int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1,9,4,32,12};
	int n = sizeof(arr)/sizeof(int);

	cout<<"Array after sorting: "<<endl;
	int *ans = mergeSort(arr,0,n-1);
	for(int i = 0; i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}