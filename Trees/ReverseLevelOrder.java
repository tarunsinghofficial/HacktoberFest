package Trees;

import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

import Trees.BinaryTree.*;
public class ReverseLevelOrder {
	public static void main(String[] args) {
		BinaryTree tree  = new BinaryTree();
		tree.root = new TreeNode(1);
		tree.root.left = new TreeNode(2);
		tree.root.right = new TreeNode(3);
		tree.root.right.left = new TreeNode(4);
		tree.root.left.right = new TreeNode(5);
		tree.root.left.left = new TreeNode(6);
		printReverse(tree.root);

	}
	static void printReverse(TreeNode node){
		if(node==null) return;
		Stack<TreeNode> st = new Stack<>();
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(node);
		while(!queue.isEmpty()){
			TreeNode n = queue.remove();
			st.push(n);
			if(n.left!=null){
				queue.add(n.left);
			}
			if(n.right!=null){
				queue.add(n.right);
			}
		}
		while(!st.isEmpty()){
			System.out.print(st.pop().val+" ");
		}
	}
}
