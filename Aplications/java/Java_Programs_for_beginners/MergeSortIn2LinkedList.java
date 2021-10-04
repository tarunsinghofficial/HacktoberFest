
// LANGUAGE: Java 
// ENV: Java 8 
// AUTHOR: Noopur Agarwal
// GITHUB: https://github.com/noopurAg
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// l1 and l2 are the two sorted Linked List 
// l1: 2->6-7 , l2: 3->4->9
class ListNode {
         int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
public class MergeSortIn2LinkedList {

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode temp = new ListNode();
        ListNode start = temp;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                temp.next = l1;
                l1=l1.next;
            }else {
                temp.next = l2;
                l2=l2.next;
            }
            temp=temp.next;
        }
        temp.next = l1!=null?l1:l2;
        start = start.next; temp = null;
        return start;
    }

    public static void main(String args[]){
        ListNode l1 = new ListNode(2);
        l1.next = new ListNode(6);
        l1.next.next = new ListNode(7);

        ListNode l2 = new ListNode(3);
        l2.next = new ListNode(4);
        l2.next.next = new ListNode(9);

        MergeSortIn2LinkedList list = new MergeSortIn2LinkedList();
        ListNode start = list.mergeTwoLists(l1,l2);
        //printing
        while(start!=null){
            System.out.print(start.val+"->");
            start=start.next;
        } 
    }

}