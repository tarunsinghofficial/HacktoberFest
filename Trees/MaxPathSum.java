package Trees;

import Trees.BinaryTree.*;
public class MaxPathSum {
	public static void main(String[] args) {
	}
	static int max = Integer.MIN_VALUE;
	public int getMax(TreeNode node){
		if(node==null) return Integer.MIN_VALUE;
		if(node.left==null && node.right==null) return node.val;
		int l = getMax(node.left);
		int r = getMax(node.right);
		if(node.left!=null && node.right!=null){
			if(l+r+node.val>max) max = l+r+node.val;
		}
		return Math.max(l, r)+node.val;

	}
}

