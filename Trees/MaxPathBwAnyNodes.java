package Trees;

import Trees.BinaryTree.*;
public class MaxPathBwAnyNodes {
	static int result = Integer.MIN_VALUE;
	// 3 cases-> Node part of the path
	// Node is the root of the path
	// Node is not a part of the path
	public int maxPathSum(TreeNode root) {
		if(root==null) return 0;
		help(root);
		return result;
	}
	private int help(TreeNode root){
		if(root==null) return 0;
		int l = help(root.left);
		int r = help(root.right);
		int ms = Math.max(Math.max(l,r)+root.val,root.val);//  node is part of the tree
		int ms1 = Math.max(ms,l+r+root.val);// node is root of max sum tree
		result = Math.max(result,ms1);
		return l+r+root.val;
	}

}
