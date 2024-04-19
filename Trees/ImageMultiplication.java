package Trees;

import Trees.BinaryTree.*;
public class ImageMultiplication {
	public static void main(String[] args) {
		
	}
	static int sum = 0;
	static int multiply(TreeNode root){
		if(root==null){
			return 0;
		}
		if(root.left!=null && root.right!=null){
			 find(root.left, root.right);
		}
		return sum+(root.val*root.val);
	}
	static void find(TreeNode n1, TreeNode n2){
		if(n1==null||n2==null) return;
		if(n1!=null && n2!=null){
			sum+= n1.val*n2.val;
		}
		find(n1.left, n2.right);
		find(n1.right, n2.left);
	}
}
