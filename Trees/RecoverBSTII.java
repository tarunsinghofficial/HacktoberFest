package Trees;

import Trees.BinaryTree.*;
public class RecoverBSTII {
	TreeNode prev = null, first = null, second = null;
	public void recoverTree(TreeNode root){
		find(root);
		int temp = first.val;
		first.val = second.val;
		second.val = temp;
	}
	private void find(TreeNode curr){
		if(curr==null) return;
		find(curr.left);
		if(prev!=null && prev.val>curr.val){
			if(first==null){
				first = prev;
			}
			second = curr;
		}
		prev = curr;
		find(curr.right);
	}


}
