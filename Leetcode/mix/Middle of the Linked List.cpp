/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        // second method
        
        vector<ListNode*> v = {head};
        while(v.back()->next!=NULL){
            v.push_back(v.back()->next);
        }
        return v[(int)v.size()/2];
        
        
        //first method

//       int count=0;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             count++;
//             temp = temp->next;
//         }
        
//         count/=2;
//         int i=0;
//         ListNode* ans;
        
//         while(i<=count){
//             ans = head;
//             head = head->next;
//             i++;
//         }
        
//         return ans;
    }
};
