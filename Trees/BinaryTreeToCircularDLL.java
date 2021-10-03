package Trees;

import Trees.BinaryTree.*;
public class BinaryTreeToCircularDLL {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(10);
		tree.root.left = new TreeNode(12);
		tree.root.left.left = new TreeNode(25);
		tree.root.left.right = new TreeNode(30);
		tree.root.right = new TreeNode(15);
		tree.root.right.left = new TreeNode(36);
		tree.root = convertToDLL(tree.root);
		display(tree.root);

	}
	static void display(TreeNode root){
		TreeNode temp = root;
		System.out.print(temp.val+" ");
		temp = temp.right;
		while(temp!=root){
			System.out.print(temp.val+" ");
			temp = temp.right;
		}
	}
	static TreeNode head = null;
	static TreeNode prev = null;
	static TreeNode convertToDLL(TreeNode root){
		convert(root);
		head.left = prev;
		prev.right = head;
		return head;
	}
	static void convert(TreeNode node){
		if(node==null) return;
		convert(node.left);
		if(prev==null){
			head = node;
		}else{
			prev.right = node;
			node.left = prev;
		}
		prev = node;
		convert(node.right);
	}
	
}
