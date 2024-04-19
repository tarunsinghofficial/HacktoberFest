package Trees;

import Trees.BinaryTree.*;
public class LongestZigZagPathII {
	public static void main(String[] args) {
		
	}
	//faster
	static int max = -1;
    public int longestZigZag(TreeNode root) {
        if(root==null||(root.left==null && root.right==null)) return 0;
        help(root);
        return max;
    }
    public int[] help(TreeNode root){
        if(root==null) return new int[]{-1,-1};
        int[] left = help(root.left);
        int[] right = help(root.right);
        max = Math.max(max,Math.max(left[1],right[0])+1);
        return new int[]{left[1]+1,right[0]+1};
    }
}

