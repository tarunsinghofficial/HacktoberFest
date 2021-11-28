package Trees;

import Trees.BinaryTree.*;
public class DiameterII {
	static int diameter(TreeNode root){
		return help(root)[0];
	}
	static int[] help(TreeNode root){
		if(root==null) return new int[]{0,-1};
		int[] left = help(root.left);
		int[] right = help(root.right);
		int dia = Math.max(left[0], Math.max(right[0], left[1]+right[1]+2));
		int height = Math.max(left[1], right[1])+1;
		return new int[]{dia,height};
	}
}
