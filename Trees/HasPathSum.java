package Trees;

import Trees.BinaryTree.*;
public class HasPathSum {
	public static void main(String[] args) {
		
	}
	static boolean find(TreeNode root,int targetSum){
		if(root==null) return false;
		targetSum-=root.val;
		if(root.left==null && root.right==null && targetSum==0) return true;
		return find(root.left, targetSum)||find(root.right, targetSum);
	}
}
