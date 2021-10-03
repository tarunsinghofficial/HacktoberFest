package Trees.BST;

public class BSTNode {
	public int data;
	public BSTNode left;
	public BSTNode right;
	public int lcount;// no of nodes on the right
	public int rcount;// no of nodes on the left
	public BSTNode(int data){
		this.data = data;
		left = right = null;
		lcount = rcount = 0;
	}
}
