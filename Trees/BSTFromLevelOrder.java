package Trees;

import Trees.BinaryTree.*;
public class BSTFromLevelOrder {
	public static void main(String[] args) {
		int[] arr = {1,2,3,4,5};
		BinaryTree tree = new BinaryTree();
		tree.root = build(arr,0);
		BinaryTree.display(tree.root);
	}
	static TreeNode build(int[] arr, int start){
		if(start>arr.length-1) return null;
		TreeNode root = new TreeNode(arr[start]);
		root.left = build(arr, 2*start+1);
		root.right = build(arr, 2*start+2);
		return root;
	}
}
