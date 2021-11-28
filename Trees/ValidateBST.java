package Trees;

import Trees.BinaryTree.*;
public class ValidateBST {
	public static void main(String[] args) {
		
	}
	public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        BST ans = help(root);
        return ans.isBST;
    }
    class BST{
        long leftMax;
        long rightMin;
        boolean isBST;
        BST(){
            leftMax = Long.MIN_VALUE;
            rightMin = Long.MAX_VALUE;
            isBST = true;
        }
    }
    public BST help(TreeNode root){
        if(root==null){
            return new BST();
        }
        BST l = help(root.left);
        BST r = help(root.right);
        BST ans = new BST();
        ans.leftMax = Math.max(root.val,Math.max(l.leftMax, r.leftMax));
        ans.rightMin = Math.min(root.val,Math.min(l.rightMin,r.rightMin));
        ans.isBST = root.val<r.rightMin && root.val>l.leftMax && l.isBST && r.isBST;
        return ans;
    }
}
