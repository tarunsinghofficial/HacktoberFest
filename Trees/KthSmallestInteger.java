package Trees;

import Trees.BST.*;
public class KthSmallestInteger {
	
	public static void main(String[] args) {

	}
	// another solution , iterative inorder
	static BSTNode kth(BSTNode root, int k){
		if(root==null) return null;
		if(k==root.lcount+1){
			return root;
		}
		if(k<root.lcount+1){
			//left subtree
			return kth(root.left, k);
		}
		//right subtree
		return kth(root.right, k-(root.lcount+1));
	}
	
}
