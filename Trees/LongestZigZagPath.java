package Trees;

import Trees.BinaryTree.*;
public class LongestZigZagPath {
	public static void main(String[] args) {
		
	}
	static class Pair{
		int left;
		int right;
		int max;
		Pair(){
			//to be set wrt edge
			left = -1;
			right = -1;
		}
	}
	static int longest(TreeNode root){
		if(root==null) return 0;
		Pair pair = help(root);
		return pair.max;
	}
	static Pair help(TreeNode root){
		if(root==null) return null;
		Pair left = help(root.left);
		Pair right = help(root.right);
		Pair pair = new Pair();
		pair.max = Math.max(Math.max(left.max, right.max), Math.max(left.right, right.left)+1);
		pair.left = left.right+1;
		pair.right = right.left+1;
		return pair;
		
	}
}
