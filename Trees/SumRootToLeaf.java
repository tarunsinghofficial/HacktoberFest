package Trees;

import Trees.BinaryTree.*;
public class SumRootToLeaf {
	public static void main(String[] args) {
		
	}
	int sum = 0;
    public int sumNumbers(TreeNode root) {
        if(root==null) return 0;
        help(root,0);
        return sum;
    }
    public void help(TreeNode root,int num){
        if(root==null) return;
        num = num*10+root.val;
        if(root.left==null && root.right==null){
            sum+=num;
            return;
        }
        if(root.left!=null){
            help(root.left,num);
        }
        if(root.right!=null){
            help(root.right,num);
        }
        
    }
}

