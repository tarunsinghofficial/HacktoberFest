// Converting phone number in string to number
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
#define pb push_back
#define fore(n) for(int i = 0;i < n;i++)
#define forr(j,n) for(int i = j;i < n;i++)
#define vll vector<long long>
typedef long long ll;
#define vi vector<int>
 
// const int INF = 1e9 + 7;
const int N = 1e5 + 3;
const int bits = 30;
 
bool compare(const vector<int> &a,const vector<int> &b){
    return a.size() < b.size();
}

void print(vll &v){ fore(v.size()) cout<<v[i]<<" ";}
void print(vector<int> &v){ fore(v.size()) cout<<v[i]<<" ";}

bool check(vector<ll> &a,ll x,ll ans){
    ll sum = 0;
    fore(a.size()){
        if(ans-a[i] > 0){
            sum += ans-a[i];
        }
    }
    if(sum <= x) return true;
    else return false;
}

ll checkPrime(ll n){
    for(ll i = 2;i <= sqrt(n);i++){
        if(n % i == 0)return i;
    }
    return n;
}

int minDis(vector<pair<ll,ll>> &v,pair<ll,ll> p,int k){
    int ind = -1;
    ll mD = 1e18;
    for(int i = 0;i < k;i++){
        if(p.first == v[i].first && p.second == v[i].second) continue;
        ll dis = abs(p.first - v[i].first) + abs(p.second - v[i].second);
        // cout<<dis<<endl;
        if(dis < mD){
            mD = dis;
            ind = i; 
        }
    }
    // cout<<v[ind].first<<v[ind].second<<endl;
    return ind;
}

void solve() {
    string s = "triple three triple four";
    map<string,int> mp;
    mp["zero"] = 0;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;    
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    mp["double"] = -2;
    mp["triple"] = -3;
    string t = "";
    string ans = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] == ' ' || i == s.length()-1){
            if(i == s.length()-1) t += s[i];
            if(mp[t] >= 0){
                ans += mp[t]+'0';
            }
            else{
                int x = abs(mp[t]);
                t = "";
                i++;
                while(s[i] != ' ' && i != s.length()){
                    t += s[i];
                    i++;
                }
                while(x--){
                    ans += mp[t]+'0';
                }
            }
            t = "";
        }
        else t += s[i];
    }
    cout<<ans<<endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
// #ifdef LOCAL
//     freopen("a.in", "r", stdin);
// #endif
 
    int t = 1;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}

