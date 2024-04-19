package Trees;
import java.util.LinkedList;
import java.util.Queue;

import Trees.BinaryTree.*;
public class RightView {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(12);
		tree.root.left = new TreeNode(10);
		tree.root.right = new TreeNode(30);
		tree.root.right.left = new TreeNode(25);
		tree.root.right.right = new TreeNode(40);
		printRight(tree.root);
	}
	static void printRight(TreeNode root){
		if(root==null) return;
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.add(root);
		queue.add(null);
		while(!queue.isEmpty()){
			TreeNode node = queue.remove();
			if(node==null && !queue.isEmpty()){
				queue.add(null);
			}
			if(node!=null && node.left!=null){
				queue.add(node.left);
			}
			if(node!=null && node.right!=null){
				queue.add(node.right);
			}
			if(node!=null && queue.peek()==null){
				System.out.print(node.val+" ");
			}
			
		}
			
	}
}


