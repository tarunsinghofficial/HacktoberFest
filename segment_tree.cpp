#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sp <<" "<<
#define pb push_back
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

const int zise = 1e5 + 7;
ll segtree[4*zise];
ll a[zise];

void build(int l, int r, int node){
  if(l==r){
    segtree[node]=a[l];
    return;
  }

  int mid = (l+r)/2;
  build(l , mid , 2*node+1);
  build(mid+1 , r ,  2*node + 2);
  segtree[node]=segtree[2*node+1] + segtree[2*node+2];
}

void update(int l, int r, int node, int i, int v){
  if(l==r){
    segtree[node]=v;
    return;
  }
  int mid = (l+r)/2;
  if(i<=mid){
    update(l,mid,2*node+1,i,v);
  }
  else if(i>mid){
    update(mid+1,r,2*node+2,i,v);
  }
  segtree[node]=segtree[2*node + 1] + segtree[2*node + 2];
}

ll sum(int l, int r, int node, int given_l, int given_r){
  if(r<given_l or l>given_r){
    return 0;
  }
  if(l>=given_l and r<=given_r){
    return segtree[node];
  }

  int mid = (l+r)/2;
  return sum(l,mid,2*node+1,given_l,given_r) + sum(mid+1,r,2*node + 2,given_l,given_r);
}

void solve(){
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  build(0,n-1,0);

  while(m--){
    int q;
    cin>>q;
    if(q==1){
      int i,v;
      cin>>i>>v;
      update(0,n-1,0,i,v);
    }
    else{
      int l,r;
      cin>>l>>r;
      cout<<sum(0,n-1,0,l,r-1)<<"\n";
    }
  }
}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  cout << fixed << setprecision(15);

  #ifndef ONLINE_JUDGE
  freopen("Input.txt","r",stdin);
  freopen("Output.txt","w",stdout);
  #endif

  // int t = 1; cin >> t; for(int i = 1; i <= t; ++i)

  solve();

  return 0;
}
