package Trees;
import java.util.LinkedList;
import java.util.Queue;

import Trees.BinaryTree.*;
public class WidthOfABinaryTree {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(12);
		tree.root.left = new TreeNode(10);
		tree.root.right = new TreeNode(30);
		tree.root.right.left = new TreeNode(25);
		tree.root.left.left = new TreeNode(25);
		tree.root.right.right = new TreeNode(40);
		tree.root.right.right.right = new TreeNode(10);
		System.out.println(maxWidth(tree.root));
	}
	static int maxWidth(TreeNode root){
		if(root==null) return 0;
		Queue<TreeNode> queue = new LinkedList<>();
		int max = 1;
		queue.add(root);
		queue.add(null);
		int tMax = 0;
		while(!queue.isEmpty()){
			TreeNode node = queue.poll();
			if(queue.isEmpty()){
				break;
			}
			if(node==null){
				max = Math.max(max, tMax);
				queue.add(null);
				tMax = 0;
			}
			if(node!=null && node.left!=null){
				queue.add(node.left);
				tMax++;
			}
			if(node!=null && node.right!=null){
				queue.add(node.right);
				tMax++;
			}
		}
		return max;

	}
}
