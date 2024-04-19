package Trees;

import Trees.BinaryTree.*;
public class LCAOfBST {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
        tree.root = new TreeNode(20);
        tree.root.left = new TreeNode(8);
        tree.root.right = new TreeNode(22);
        tree.root.left.left = new TreeNode(4);
        tree.root.left.right = new TreeNode(12);
        tree.root.left.right.left = new TreeNode(10);
        tree.root.left.right.right = new TreeNode(14);
		System.out.println(LCA(tree.root,10,14).val);
	}
	//assuming p1>p2
	static TreeNode LCA(TreeNode root, int p1, int p2){
		if(root==null) return null;
		if(root.val>p1 && root.val>p2) return LCA(root.left, p1, p2);
		else if(root.val<p1 && root.val<p2) return LCA(root.right,p1,p2);
		return root;
	}
}
