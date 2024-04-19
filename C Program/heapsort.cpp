#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
  }
}
void heapsort(vector<int>& arr, int n)
{
  for(int i = n/2 - 1; i >= 0; --i)
    heapify(arr,n,i);
  
  for(int i = n - 1; i > 0; --i)
  {
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}
void solve(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; ++i)
      cin >> arr[i];
  heapsort(arr,n);
  cout << "Sorted Array is : ";
  for(int i = 0; i < n; ++i)
      cout << arr[i] << " ";
  cout << "\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  int t = 1;
//   cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
