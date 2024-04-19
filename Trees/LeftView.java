package Trees;

import java.util.LinkedList;
import java.util.Queue;

import Trees.BinaryTree.*;
public class LeftView {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(12);
		tree.root.left = new TreeNode(10);
		tree.root.right = new TreeNode(30);
		tree.root.right.left = new TreeNode(25);
		tree.root.right.right = new TreeNode(40);
		printLeft(tree.root);
		// BinaryTree.display(tree.root);
	}
	static void printLeft(TreeNode root){
		if(root==null) return;
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.add(root);
		queue.add(null);
		System.out.print(root.val+" ");
		while(!queue.isEmpty()){
			TreeNode node = queue.remove();
			if(node==null && !queue.isEmpty()){
				queue.add(null);
				System.out.print(queue.peek().val+" ");
			}
			if(node!=null && node.left!=null){
				queue.add(node.left);
			}
			if(node!=null && node.right!=null){
				queue.add(node.right);
			}
			
		}
	}
}
