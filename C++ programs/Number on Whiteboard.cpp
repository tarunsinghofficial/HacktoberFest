#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
using namespace std;

int main(){
	int t;
	cin>>t;
    while(t--){
            int n;
            cin>>n;
            int m=n-1;
            cout<<2<<endl;
		    
		    if(n==2)cout<<1<<" "<<2<<endl;
		    else{
		    fo(i,m){
		        if(i==1)cout<<n<<" "<<n<<endl;
		        else{
		        cout<<n<<" "<<n-2<<endl;
		        n--;}
		        
		    }
		    }
		    
		  }
	return 0;
}
