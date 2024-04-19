package Trees;
import Trees.BinaryTree.*;
public class FlattenABST {
	public static void main(String[] args) {
		
	}
	public void flatten(TreeNode root) {
		flattenHelp(root);
   }
   public TreeNode flattenHelp(TreeNode root){
	   if(root==null) return null;
	   TreeNode left = flattenHelp(root.left);
	   TreeNode right = flattenHelp(root.right);
	   root.left = null;
	   root.right = left;
	   TreeNode temp = root;
	   if(temp!=null){
		   while(temp.right!=null){
			   temp = temp.right;
		   }
		   temp.right = right;
	   }
	   return root;
   }
	
}
