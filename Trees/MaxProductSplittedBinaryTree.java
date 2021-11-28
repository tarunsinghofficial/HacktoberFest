package Trees;

import Trees.BinaryTree.*;
public class MaxProductSplittedBinaryTree {
	static int m = 1000000007;
	long max;
   public int maxProduct(TreeNode root) {
	   max = Integer.MIN_VALUE;
	   long sum = sum(root);
	   traverseAndFind(root,sum);
	   max =  max%m;
	   // System.out.println(sum);
	   return (int) max;
	   
   }
   public int traverseAndFind(TreeNode root,long sum){
	   if(root==null) return 0;
	   //including in left subtree
	  int l =  traverseAndFind(root.left,sum)%m;
	  int r = traverseAndFind(root.right,sum)%m;
		// System.out.println(s2);
	   max = Math.max(max,l*(sum-l));
	   max = Math.max(max,r*(sum-r));
	   return (l+r+root.val)%m;
	  
   }
   public long sum(TreeNode root){
	   if(root==null) return 0;
	   return root.val+sum(root.left)+sum(root.right);
   }
}
