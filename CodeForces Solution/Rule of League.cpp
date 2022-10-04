#include <bits/stdc++.h>
using namespace std;
#define print(x) for(auto & it : x)cout<<it<<' '; cout<<endl;
#define printd(x) for(auto & it : x)cout<<it.first<<' '<<it.second<<endl;
#define all(x) x.begin(),x.end()
#define int long long 
const int MOD =  1e9+7;

void solve()
{
    int n,a,b; cin>>n>>a>>b;
    if(a == 0 and b == 0){
        cout<<-1<<endl;
    }else if( a == 0 or b == 0){
        if(a == 0) a = b;
        bool ok = true;
        if( (n-1) % a == 0 and (n-1) <= a*n){
            int k = 1,i = 0;
            vector<int>res;
            int val = (n-1)/a;
           // cout<<val<<endl;           
            while( i < val){
                for(int i = 1;i<=a;i++){
                    res.push_back(k);
                }
                i++;
                if( ok){
                k+=a+1;
                ok = false;
                }else{
                 k += a;
                }
            }
          //  print(res)
            if( res.size() == n-1){
                for(auto & it : res){
                    if(it > n){
                        cout<<-1<<endl;return;
                    }
                }
                print(res)
            }else{
                cout<<-1<<endl;
            }
        }else{
            cout<<-1<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}

signed main()
{	
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)   
        solve();

    return 0;    
}