package Trees;

import Trees.BinaryTree.*;
public class BSTFromPostOrder {
	public static void main(String[] args) {
		int[] p = {1, 7, 5, 50, 40, 10};
		BinaryTree tree = new BinaryTree();
		tree.root = build(p, 0, p.length-1);
		BinaryTree.display(tree.root);
	}
	static TreeNode build(int[] post, int start, int end){
		if(start>end) return null;
		TreeNode root = new TreeNode(post[end]);
		if(start==end) return root;
		int idx = start;
		while(post[end]>post[idx]){
			idx++;
		}
		int k = idx-start;
		root.left = build(post, start, start+k-1);
		root.right = build(post, start+k, end-1);
		return root;
	}
}
