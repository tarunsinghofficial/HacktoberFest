/*
    Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/

vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    int n = (int)s.size();
    //binary representation from 1 to 2^n
    for(int i = 1; i < (1 << n); i++) {
        string res = "";
        int temp = i, j = 0;
        while(temp) {
            if(temp & 1) 
                res += s[j];
            j++;
            temp >>= 1;
        }
        // no empty substring
        if(!res.empty())
            ans.push_back(res);
    }
    // for lexographic order 
    sort(ans.begin(), ans.end());
    return ans;
}

/* 
USING RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	void generateSubstrings(string s, vector<string> &results, int idx = 0, string ans = "") {
    // base case
    if(idx == s.size()) {
        // don't include empty substring
        if(ans != "")
            results.push_back(ans);
        return;
    }
    // recursive calls:
    // exclude the current element
    generateSubstrings(s, results, idx + 1, ans);
    // include the current element
    generateSubstrings(s, results, idx + 1, ans + s[idx]);
}


vector<string> AllPossibleStrings(string s){
    // Code here
    vector<string> results;
    generateSubstrings(s, results);
    sort(results.begin(), results.end());
    return results;
}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
*/