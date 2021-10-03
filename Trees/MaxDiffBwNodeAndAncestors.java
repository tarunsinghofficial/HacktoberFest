package Trees;

import Trees.BinaryTree.*;
public class MaxDiffBwNodeAndAncestors {
	public static void main(String[] args) {
		
	}
	static int find(TreeNode root, int res){
		if(root==null) return 0;
		if(root.left==null && root.right==null) return root.val;
		int l = find(root.left, res);
		int r = find(root.right, res);
		int val = Math.min(l, r);
		res = Math.max(res, root.val-val);
		return Math.min(val, root.val);
	}

}
