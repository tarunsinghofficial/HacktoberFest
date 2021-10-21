#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
   stack<string> st;

   cout<<"Enter a string\n";
   string s;
   getline(cin,s);
   if(s[0]==' ')
   {
       s=s.substr(1);
   }
   if(s[s.length()-1])
   {
       s=s+' ';
   }
   string k="";
   int i=0;
   while (s[i]!='\0')
   {
       if(s[i]==' ')
       {
           st.push(k);
           k=' ';
           i++;
           continue;
       }

       k=k+s[i];
       i++;
   }
   while (!(st.empty()))
   {
       cout<<st.top()<<" ";
       st.pop();
   }
   cout <<endl;
   
}