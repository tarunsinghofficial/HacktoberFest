package Trees;

public class PopulatingNextRightPointers {
	static class Node{
		int val;
		Node left,right, next;
	}
	public Node connect(Node root) {
        if(root==null) return null;
        root.next = null;
        help(root.left,root);
        help(root.right,root);
        return root;
    }
    public void help(Node node, Node parent){
        if(node==null) return;
        if(parent.right==node && parent.next==null){
            node.next = null;
        }
        else if(parent.right==node && parent.next!=null){
            node.next = parent.next.left;
        }
        else{
            node.next= parent.right;
        }
        help(node.left, node);
        help(node.right, node);
    }
}
