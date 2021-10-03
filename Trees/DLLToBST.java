package Trees;

public class DLLToBST {
	static class Node{
		int data;
		Node prev;
		Node next;
		Node(int data){
			this.data = data;
			next = prev = null;
		}
	}
	static class DLL{
		public Node head = null;
		public Node prev = null;
		public void insert(int data){
			Node node = new Node(data);
			if(prev==null){
				head = node;
			}else{
				prev.next = node;
				node.prev = prev;
			}
			prev = node;
		}
	}
	public static void main(String[] args) {
		DLL ll = new DLL();
		ll.insert(1);
		ll.insert(2);
		ll.insert(3);
		ll.head = convert(ll.head);
		display(ll.head);
	}

	static void display(Node root){
		if(root.prev==null) return;
		String str = root.data+" L: ";
		str+=root.prev==null?"null":root.prev.data+"";
		str+=" R: ";
		str+=root.next==null?"null":root.next.data+"";
		System.out.println(str);
		display(root.prev);
		display(root.next);

	}
	static Node convert(Node root){
		if(root==null||(root.next==null&&root.prev==null)) return root;
		Node mid = mid(root);
		Node temp = mid.next;
		if(mid.prev!=null){
			mid.prev.next=null;
		}
		mid.prev = null;
		if(mid.next!=null){
			mid.next.prev = null;
		}
		mid.next = null;
		mid.prev = convert(root);
		mid.next = convert(temp);
		return mid;
	}
	static Node mid(Node node){
		Node slow = node;
		Node fast = node;
		while(fast.next!=null && fast.next.next!=null){
			fast = fast.next.next;
			slow = slow.next;
		}
		return slow;
	}
}