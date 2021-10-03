package Trees.BST;

public class BST {
	public BSTNode root;
	public void insert(int data){
		root = insertHelper(root, data);
	}
	private BSTNode insertHelper(BSTNode root,int data){
		if(root==null){ 
			return new BSTNode(data);
		}
		if(data<root.data){
			insertHelper(root.left, data);
			root.lcount++;
		}else{
			insertHelper(root.right, data);
			root.rcount++;
		}
		return root;
	}
}
