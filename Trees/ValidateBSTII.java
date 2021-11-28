package Trees;

import Trees.BinaryTree.*;
public class ValidateBSTII {
	public static void main(String[] args) {
		
	}
	 // 75/80 testcase passed
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        return help(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    public boolean help(TreeNode root, long min, long max){
        if(root==null) return true;
        if(root.val< min || root.val>max) return false;
        boolean l = help(root.left,min,root.val-1);
        boolean r = help(root.right, root.val+1,max);
        if(!l||!r) return false;
        return true;
    }
}
