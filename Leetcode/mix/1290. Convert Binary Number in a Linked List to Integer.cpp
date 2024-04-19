/*
1290. Convert Binary Number in a Linked List to Integer
Easy

1066

62

Add to List

Share
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

class Solution {
public:
    int binartodec(string s){  // 101
        int dec = 0;
        int base = 1;
        int n = (int)s.length()-1;   /// 3 
        for(int i=n; i>=0; i--){ 
            if(s[i] == '1')  
                dec+=base;   // 2
            base*=2;   // 2 4 
        }
        return dec;
    }
    int getDecimalValue(ListNode* head) {
        string s;
         while(head != NULL){
             int data = head->val;
             char x = (data==1) ? '1' : '0';
             s += x;
             head = head->next;
         }
         int ans = binartodec(s);
        return ans;
    }
};


