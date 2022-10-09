#include<bits/stdc++.h>
using namespace std;

void explainList(){
    list<int> ls;

    ls.push_back(2);// {2}
    ls.emplace_back(4); // {2,4}
    
    //It is not available in vector
    ls.push_front(5);   //{5,2,4} It is very light in terms of time complexity
    // rest fn are same as vector

}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);// {1}
    dq.emplace_back(2);// {1,2}
    dq.push_front(4);// {4,1,2}
    dq.emplace_front(3); // {3,4,2,1}

    dq.pop_back();//    {3,4,1}
    dq.pop_front();//   {4,1}

    cout << dq.front() << endl;  
    cout << dq.back() << endl; 
}

void explainStack(){
    stack<int> st;
    st.push(1); // {1}
    st.push(2);    // {2,1}
    st.push(3);    // {3,2,1}
    st.push(4);    // {4,3,2,1}
    st.emplace(5); // {5,4,3,2,1}

    cout << st.top() << endl; // "st[1] not works here."
    st.pop(); // {4,3,2,1}

}

void explainQueue(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}
    q.back() += 5;
    cout << q.back() << endl; // prints 9. {1,2,9}

    cout << q.front() << endl; // prints 1

    q.pop(); // {2,9}
    cout << q.front() << endl;  // prints 2

}

void explainPriorityQueue(){
    // aama sauthi moto element top pr enter thay and e pa6i insert krie m utarata kram ma gothvay
    // int hoy to max num, char hoy to max char upr rahe.
    // it is not linear data structure. it maintains a tree.
    priority_queue<int>pq;
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout << pq.top() << endl; // prints 10

    pq.pop();   // {8,5,2}
    cout << pq.top() << endl; // prints 8  

    //Minimum heap
    priority_queue<int, vector<int>,greater<int>>pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    pq.top(); // prints 2
}

void explainSet(){
    //Stores everything in sorted order and elements must be unique.
    
    set<int>st;
    st.insert(1);   //  {1}
    st.emplace(2);  //  {1,2}
    st.insert(2);   //  {1,2}
    st.insert(4);   //  {1,2,4}
    st.insert(3);   //  {1,2,3,4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    auto it = st.find(3); // it returns an iterator which points to 3

    auto it = st.find(6); // if ele is not present it will return st.end() means location after last ele

    st.erase(5); // erase 5. takes logarithmic time

    int cnt = st.count(2); // it returns 1 if occurence is present otherwise return 0 
}

void explainMultiSet(){
    // Everything same as set.
    // Its like ArrayList of Java
    // Stores duplicate element also

    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(2); // {1,1,2}

    ms.erase(1); // erase all 1s.
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    int cnt = ms.count(1); // it will return 3

    //only single 1 erased
    ms.erase(ms.find(1));
}

void explainMap(){
    // Map Stores the unique keys in sorted order of keys similar to set data structure. 

    map<int,int> mpp1;
    map<int,pair<int,int>> mpp2;
    map<pair<int,int>,int> mpp3;

    mpp1[1] = 2; // {1,2} -> where 1 is key and 2 is value
    mpp1.emplace(3,1); // {3,1}
    mpp1.insert({2,4}); //{2,4}

    mpp3[{2,3}] = 10; // {{2,3},10} -> {2,3} is key and 10 is val

    //Printing 
    for (auto it:mpp1){
        cout << it.first << ", " << it.second << endl; 
    }
    
    cout << mpp1[1] << endl; // gives value at key = 1

    auto it = mpp1.find(3);
    cout<<(*(it)).second;
}

/************* Algorithms ************/

void explainExtra(){
    int a[] = {3,5,2,9,4};
    sort(a, a + 5);//it will sort element before of a+5

}

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << v[1] << " ::: less used method :" << v.at(1) << endl;
    // cout << "Size of vector: " << v.size();

    // ******* Iterator ********

    vector<int>::iterator i = v.begin(); // v.begin() actually gives us the address of 1st element
    cout << *(i) << endl;   //  v.begin() gives us address of data so we have to de-referance it to get the data
    i = i+2;    // now it points to 10
    cout << *(i) << endl; 
    i = v.end(); // it will not point to last node. It points to location after last node. 
    //               so now i-- will give us location of last node
    cout << "Last ele: " <<v.back()<< endl; //It points to the last element of vector

    // ***** Printing Vector - Old method *****
    for(vector<int>::iterator it =v.begin(); it != v.end(); it++){
        cout << *(it) << endl; 
    }

    //Good Method
    for(auto it =v.begin(); it != v.end(); it++){   //auto means inferred dataType automatically
        cout << *(it) << endl; 
    }

    //For-each Loop
    for(auto it:v){     // It will iterate over integer dataType
        cout << it << endl; 
    }

    //***** Remove element from the vector *****

    v.erase(v.begin()+1);   // signature : v.erase(locationOfElement). it'll remove 2nd ele.
    
    //{10,20,30,40,50}
    v.erase(v.begin()+1,v.begin()+3); // v.erase(start,end). it'll remove 2nd ele to 3rd ele. its like [start,end)
    //Output will be {10,40,50}

    // ***** Insert Function ***** -> it is costly in terms of time complexity.

    //{10,20,30,40,50}
    v.insert(v.begin(),300); // {300,10,20,30,40,50}
    v.insert(v.begin()+1,2,70); // {300,70,70,10,20,30,40,50} sign: (location,NoOfPositionsToOccupy,value)

    cout << v.size() << endl; //size of vector
    v.pop_back(); //pop out last element

    cout << "v.empty() : " << v.empty() << endl; //it returns 0 as false and 1 as true
    v.clear();  //clear whole vector
    cout << "v.empty() : " << v.empty() << endl; 
    explainDeque();
}
