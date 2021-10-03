package Trees;

import Trees.BinaryTree.*;
public class DiameterOfTree {
	public static void main(String[] args) {
		
	}
	static int max = 0;
	public int diameter(TreeNode root){
		help(root);
		return max;
	}
	private int help(TreeNode node){
		if(node==null) return -1;
		int left = help(node.left);
		int right = help(node.right);
		max = Math.max(max, left+right+2);
		return Math.max(left, right)+1;

	}

}
