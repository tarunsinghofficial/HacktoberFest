package Trees;

import Trees.BinaryTree.*;
public class HouseRobber {
	public static void main(String[] args) {
		
	}
	static int rob(TreeNode root){
		if(root==null) return 0;
		Pair ans = help(root);
		return Math.max(ans.yes, ans.no);
	}
	static class Pair{
		int yes;
		int no;
		Pair(){
			yes = 0;
			no = 0;
		}
	}
	static Pair help(TreeNode root){
		if(root==null) return new Pair();
		Pair l = help(root.left);
		Pair r = help(root.right);
		Pair ans = new Pair();
		ans.yes = root.val + l.no + r.no;
		ans.no = Math.max(l.no, l.yes)+Math.max(r.no, r.yes);
		return ans;
	}
}
