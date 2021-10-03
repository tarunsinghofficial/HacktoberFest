// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

class Solution {
public:
    bool isValid(string s) {
        int i,j,n=s.size();
        unordered_map<char,int> m;
        char a='a',b='b',c='c';
        stack<char> stack;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stack.push(s[i]);
            if(s[i]==')')
            {
                if(stack.empty() || stack.top()!='(') return false;
                else stack.pop();
                
            }
            if(s[i]=='}')
            {
                if(stack.empty() || stack.top()!='{') return false;
                else stack.pop();
                
            }
            if(s[i]==']')
            {
                if(stack.empty() || stack.top()!='[') return false;
                else stack.pop();
                
            }
        }
        if(stack.empty()) return true;
        else return false;
    }
};
