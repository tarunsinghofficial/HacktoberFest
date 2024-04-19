package Trees;

import Trees.BinaryTree.*;
public class ColoringGame {
	class Solution {
		public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
			//Basic intution : whoever colors more than n/2 nodes wins
			TreeNode node = find(root,x);// find node in the tree
			/*
			3 cases to choose the node from
				Left subtree
				Right subtree
				Above the current node;
			*/ 
			int lc  = count(node.left);
			int rc = count(node.right);
			return Math.max(n-lc-rc-1,Math.max(lc,rc))>n/2;
			
		}
		public TreeNode find(TreeNode root , int x){
			if(root==null) return null;
			if(root.val==x) return root;
			TreeNode l = find(root.left,x);
			TreeNode r = find(root.right,x);
			return l==null?r:l;
		}
		public int count(TreeNode root){
			if(root==null) return 0;
			int l = count(root.left);
			int r = count(root.right);
			return l+r+1;
		}
	}
}
