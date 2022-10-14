# include <iostream>
# include <fstream>
# include <bits/stdc++.h>
using namespace std;

vector<vector<string>> anagram(vector<string>& strs) {
int n = strs.size();
unordered_map<string, vector<string>> mp;
vector<vector<string>>ans;
int i=0;
while(i<n){
string a = strs[i];
sort(a.begin(), a.end());
mp[a].push_back(strs[i]);
i++;
}
for(auto i=mp.begin(); i!= mp.end(); i++){
ans.push_back(i->second);
}
return ans;
}
int main (int argc, char *argv[]){
vector<string>input;
if(argc == 1){
input = {"pans","pots","opt","snap","stop","tops","stop"};
}
else{
char *fname = argv[1];
fstream newfile;

newfile.open(fname,ios::in);
string tp;
while(getline(newfile, tp)){
input.push_back(tp) ;
}
}
vector<vector<string>> output = anagram(input);
for(int i = 0;i < output.size(); ++i){
for(int j = 0;j < output[i].size(); ++j){
cout<<output[i][j]<<" ";
}
cout<<endl;
}
return 0;
}