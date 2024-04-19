package Trees;

import Trees.BinaryTree.*;
public class DistributeCoins {
	public static void main(String[] args) {
		
	}
	static int count = 0;
	static int dist(TreeNode root){
		if(root==null) return 0;
		help(root, null);
		return count;
	}
	static void help(TreeNode root, TreeNode parent){
		if(root==null) return;
		help(root.left, root);
		help(root.right, root);
		if(root.val<1 && parent!=null){
			int dif = 1-root.val;
			count+=dif;
			parent.val-=dif;
		}
		else if(root.val>1 && parent!=null){
			int dif = root.val-1;
			count+=dif;
			parent.val+=dif;
		}
	}
}
