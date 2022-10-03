

class ListNode {
     int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    ListNode reverse(ListNode l1){
        ListNode next=null;
        ListNode cur=l1;
        ListNode prev=null;
       while(cur!=null){
           next=cur.next;
           cur.next=prev;
           prev=cur;
           cur=next;
       }
        return prev;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode cur1=reverse(l1);
        ListNode cur2=reverse(l2);
        int carry=0;
        ListNode head=new ListNode(0);
        ListNode cur=head;
        while(cur2!=null || cur1!=null || carry!=0){
            int x=(cur1!=null)?cur1.val:0;
            int y=(cur2!=null)?cur2.val:0;            
            int curVal=x+y+carry;
            carry=curVal/10;
            cur.next=new ListNode(curVal%10);
            cur=cur.next;
            if(cur2!=null){
            cur2=cur2.next;                
            }
            if(cur1!=null){
            cur1=cur1.next;
            }
        }
         ListNode finalHead=reverse(head.next);
        return finalHead;
    }
}