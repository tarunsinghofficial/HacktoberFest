package Trees;

import java.util.ArrayList;

import Trees.BinaryTree.*;
public class AllKSumPath {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(1); 
		tree.root.left = new TreeNode(3); 
		tree.root.left.left = new TreeNode(2); 
		tree.root.left.right = new TreeNode(1); 
		tree.root.left.right.left = new TreeNode(1); 
		tree.root.right = new TreeNode(-1); 
		tree.root.right.left = new TreeNode(4); 
		tree.root.right.left.left = new TreeNode(1); 
		tree.root.right.left.right = new TreeNode(2); 
		tree.root.right.right = new TreeNode(5); 
		tree.root.right.right.right = new TreeNode(2); 
		int k = 5; 
		findK(tree.root, k);
	}
	static void findK(TreeNode root, int k){
		if(root==null) return;
		ArrayList<Integer> path = new ArrayList<>();
		findkHelp(root, path, k);
	}
	static void findkHelp(TreeNode root, ArrayList<Integer> path, int k){
		if(root==null) return;
		path.add(root.val);
		findkHelp(root.left, path, k);
		findkHelp(root.right, path, k);
		int f = 0;
		//check at every node
		for(int j=path.size()-1;j>=0;j--){
			f+=path.get(j);
			if(f==k) printk(path, j);
		}
		// backtraking
		path.remove(path.size()-1);
	}
	static void printk(ArrayList<Integer> arr,int j){
		for(int i=j;i<arr.size();i++){
			System.out.print(arr.get(i)+" ");
		}
		System.out.println();
	}
}
