#include<bits/stdc++.h>
using namespace std;

/*Maps - it prints output in an order either in numeric order or lexiograhic order and therefore it's time complexity
          is O(log(n)).it follows red black tree method for providing the required output.
void print(map<string,int> m){
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main(){
    int n;
    string s;
    map<string,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        m[s]++;
    }
    map<string,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    print(m);
    return 0;
}*/

/* Unordered Maps - it prints output in random order and therefore it's time complexity is O(1).
                    it follows hashtable method for providing the required output.
void print(unordered_map<string,int> m){
    for(auto &it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main(){
    int n;
    string s;
    unordered_map<string,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        m[s]++;
    }
    map<string,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    print(m);
    return 0;
}*/

/* Pairs : They are basically when pairing is required of same or different data types. 
    int main(){
    int a[]={1,2,3};
    int b[]={4,5,6};
    pair<int,int> p_arr[3];
    p_arr[0]={1,4};
    p_arr[1]={2,5};
    p_arr[2]={3,6};
    for(int i=0;i<3;i++){
        cout<<p_arr[i].first<<" "<<p_arr[i].second<<endl;
    }
    return 0;
}*/

/* Vectors : vectors are arrays of dynamic nature.
    void print(vector<int> vec){
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
        print(v);
    }
    return 0;
}*/

/* Array of vectors : We make vectors in the form of arrays and inside every array box there exist another vector. In this case,
                      we have to initialize rows same as arrays but columns are dynamic in nature same as vectors.
    int main(){
    int n,m,x;
    cin>>n;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>x;
            v[i].push_back(x);
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"size : "<<v[i].size()<<endl;
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

/*  Vectors of vectors : We make vectors and inside every vector box there exist another vector. In this case,
                         the rows are dynamic in nature same as vectors and columns are also dynamic in nature same as vectors.
    void print(vector<int> vec){
    cout<<endl<<"size : "<<vec.size()<<endl;
    for(int j=0;j<vec.size();j++){
        cout<<vec[j]<<"  ";
    }
}
int main(){
    int n,m,k;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        cin>>m;
        vector<int> temp;
        for(int j=0;j<m;j++){
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }
    for(int i=0;i<n;i++){
        print(v[i]);
    }
    return 0;
}*/

/* iterator : Works as a pointer when we use containers.
    int main(){
    vector<pair<int,int>> v={{1,2},{2,3},{3,4},{4,5}};
    vector<pair<int,int>> :: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    return 0;
}*/

/* Auto : Also works as an iterator in case of containers but using it is very easy because it can automatically detect 
          any type of data and therefore print the required output.
    int main(){
    vector<pair<int,int>> v={{1,2},{2,3},{3,4},{4,5}};
    for(auto it=v.begin();it!=v.end();it++){
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    for(auto it : v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}*/

/* Sets : Generally,these are used to store data in an order either it is in numeric or lexiographic order.
          their implementation takes O(log(n)) time complexity and just like maps they follows Red black tree method.  
void print(set<string> st){
    for(auto values : st){
        cout<<values<<endl;
    }
}
int main(){
    set<string> s;
    string str;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str);
    }
    auto it = s.find(abc) // it returns the iterator
    print(s);
    return 0;
}*/

/* Unordered_Sets : Generally,these are used to store data in random order and mostly used when we have to find some datain our set.
                    their implementation takes O(1) time complexity and just like unordered maps they follows hashing method.  
void print(unordered_set<string> st){
    for(auto values : st){
        cout<<values<<endl;
    }
}
int main(){
    unordered_set<string> s;
    string str;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str);
    }
    auto it = s.find(abc) // it returns the iterator
    print(s);
    return 0;
}*/

/* MultiSets : Generally,these are used to store data in an order either it is in numeric or lexiographic order.
               their implementation takes O(log(n)) time complexity and the difference betweeen sets and multisets is that 
               in case of sets we can't store duplicates but in case of multisets we can store duplicates also. 
    int main(){
    int t;
    cout<<"Enter the no. of testcases : ";
    cin>>t;
    while(t--){
        int n,k,candies,total=0;
        cout<<"Enter No. of Bags : "<<endl;
        cin>>n;
        cout<<"Enter No. of Minutes : "<<endl;
        cin>>k;
        multiset<int> m;
        cout<<"Enter the No. of Candies in the Bag : "<<endl;
        for(int i=0;i<n;i++){
            cin>>candies;
            m.insert(candies);
        }
        while(k--){
            auto it = m.end();
            it--;
            total += (*it);
            int nw=(*it);
            m.erase(it);
            m.insert(nw/2);
        }
        cout<<total;
    }
}*/

/* Nested Containers : 
    int main(){
    map<pair<string,string>,vector<int>> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string strone,strtwo;
        int c;
        cin>>strone>>strtwo>>c;
        for(int j=0;j<c;j++){
            int no;
            cin>>no;
            m[{strone,strtwo}].push_back(no);
        }
    }
    for(auto &pr : m){
        cout<<pr.first.first<<" "<<pr.first.second<<" "<<pr.second.size()<<endl;
        for(auto &p : pr.second){
            cout<<p<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}*/

/* Nested Containers :
    int main(){
    int n;
    cout<<"Enter the no. of students : "<<endl;
    cin>>n;
    map<int, multiset<string>> m;
    for(int i=0;i<n;i++){
        int marks;
        string str;
        cout<<"Firstly Enter the Marks of Students and Secondly Enter Name of Student : "<<endl;
        cin>>marks>>str;
        m[marks].insert(str);
    }
    cout<<"The Data of students in Decreasing order of their Marks : "<<endl;
    auto it = (--m.end());
    while(true){
        for(auto &mrks : (*it).second){
            cout<<mrks<<" "<<(*it).first<<endl;
        }
        if(it==m.begin())
        break;
        it--;
    }
}*/

/* stack : Used to store different data type elements and it stores data in last in first out (lifo) mode.
    int main(){
    stack<string> s;
    s.push("ab");
    s.push("bc");
    s.push("cd");
    s.push("de");
    s.push("ef");
    s.push("fg");
    s.push("gh");
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}*/

/* queue : Used to store different data type elements and it stores data in first in first out (fifo) mode.
int main(){
    queue<string> q;
    q.push("ab");
    q.push("bc");
    q.push("cd");
    q.push("de");
    q.push("ef");
    q.push("fg");
    q.push("gh");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}*/

/* Balancing Parenthesis using stacks : 
    unordered_map<char,int> m={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};
    void print(string &s){
    stack<char> str;
    for(char &brkt: s){
        if(m[brkt] < 0){
            str.push(brkt);
        }
        else{
            if(s.empty()){
                cout<<"No";
                return;
            }
            char top = str.top();
            str.pop();
            if(m[brkt]+m[top] != 0){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    if(str.empty()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main(){
    int t;
    cout<<"Enter the no. of test cases : "<<endl;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        print(s);
    }
}*/

/* Next Greater Element using stacks :
    vector<int> NGE(vector<int> &vec){
    int m=vec.size();
    vector<int> ans(m);
    stack<int> st;
    for(int i=0;i<m;i++){
        while(!st.empty() && vec[i]>vec[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()]=-1;
        st.pop();
    }
    return ans;
} 
int main(){
    int n;
    cout<<"Enter the no. of values : "<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the Values : "<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> nge = NGE(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" = "<< (nge[i] == -1 ? -1 : v[nge[i]])<<endl;
    }
    return 0;
}*/


/* sort function used in arrays as follows to sort our array data
    int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}*/


/* sort function used in vectors as follows to sort our vector data
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<"\t";
    }
    return 0;
}*/

/* Comparator function in sort funtion used to define the custom(Manual) behavior of our sort function.
bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first<p2.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<"\t"<<v[i].second<<endl;
    }
    return 0;
}*/

/*bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first<p2.first;
}*/

/* lower bound and upper bound in case of arrays :
    int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Enter the value : "<<endl;
    cin>>k;
    int *ptr1=lower_bound(arr,arr+n,k);
    if(ptr1 == arr+n){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*ptr1)<<endl;
    }
    int *ptr2=upper_bound(arr,arr+n,k);
    if(ptr2 == arr+n){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*ptr2)<<endl;
    }
    return 0;
}*/

/* lower bound and upper bound in case of vectors :
int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<"The sorted vector is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Enter the value : "<<endl;
    cin>>k;
    auto it1 =lower_bound(arr.begin(),arr.end(),k);
    if(it1 == arr.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*it1)<<endl;
    }
    auto it2 =upper_bound(arr.begin(),arr.end(),k);
    if(it2 == arr.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*it2)<<endl;
    }
    return 0;
}*/

/* lower bound and upper bound in case of sets :
int main(){
    int n,k,val;
    cin>>n;
    set<int> arr;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.insert(val);
    }
    cout<<"The set is : "<<endl;
    for(auto &value : arr){
        cout<<value<<" ";
    }
    cout<<endl<<"Enter the value : "<<endl;
    cin>>k;
    auto it1 = arr.lower_bound(k);
    if(it1 == arr.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*it1)<<endl;
    }
    auto it2 = arr.upper_bound(k);
    if(it2 == arr.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<(*it2)<<endl;
    }
    return 0;
}*/

/* STL Inbuilt Algoritms for vectors : 
    int main(){
    int n,k,l;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int max = *max_element(v.begin(),v.end());
    int min = *min_element(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0);
    cout<<"Enter the element for getting count : "<<endl;
    cin>>k;
    int cnt = count(v.begin(),v.end(),k);
    cout<<"Enter the element to find : "<<endl;
    cin>>l;
    auto element = find(v.begin(),v.end(),l);
    cout<<"The Max Element is : "<<max<<endl;
    cout<<"The Min Element is : "<<min<<endl;
    cout<<"The Sum of Elements is : "<<sum<<endl;
    cout<<"The Count of "<<k<<" is : "<<cnt<<endl;
    if(element != v.end()){
       cout<<"The Element "<<(*element)<<" is present"<<endl;
    }
    else{
        cout<<"The Element"<<l<<" is not present "<<endl;
    }
    reverse(v.begin(),v.end());
    cout<<"The Reverse Vector is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}*/

/* STL Inbuilt Algoritms for Arrays :
    int main(){
    int n,k,l;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int max = *max_element(v,v+n);
    int min = *min_element(v,v+n);
    int sum = accumulate(v,v+n,0);
    cout<<"Enter the element for getting count : "<<endl;
    cin>>k;
    int cnt = count(v,v+n,k);
    cout<<"Enter the element to find : "<<endl;
    cin>>l;
    int *element = find(v,v+n,l);
    cout<<"The Max Element is : "<<max<<endl;
    cout<<"The Min Element is : "<<min<<endl;
    cout<<"The Sum of Elements is : "<<sum<<endl;
    cout<<"The Count of "<<k<<" is : "<<cnt<<endl;
    if(element != v+n){
       cout<<"The Element "<<(*element)<<" is present"<<endl;
    }
    else{
        cout<<"The Element"<<l<<" is not present "<<endl;
    }
    reverse(v,v+n);
    cout<<"The Reverse Vector is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}*/

/* Inbuilt STL Algorithms and Lambda Function : 
int main(){
    cout<< [](int x){
        return x+2;
    } (9) <<endl;
    auto sum = [](int x,int y){
        return x+y;
    };
    cout<<sum(9,7);
    return 0;
    vector<int> v = {1,3,6,2};
    cout<<all_of( v.begin() , v.end() , [](int x){ return x>0; } )<<endl;
    cout<<any_of( v.begin() , v.end() , [](int x){ return x>0; } )<<endl;
    cout<<none_of( v.begin() , v.end() , [](int x){ return x>0; } )<<endl;
    return 0;
}*/