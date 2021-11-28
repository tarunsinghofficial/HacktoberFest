package Trees;
import java.util.ArrayList;

import Trees.BinaryTree.*;
public class Merge2BST {
	public static void main(String[] args) {
		BinaryTree tree1 = new BinaryTree();
		BinaryTree tree2 = new BinaryTree();
		tree1.root =new TreeNode(2);
		tree1.root.left =new TreeNode(1);
		tree1.root.right =new TreeNode(3);
		tree2.root = new TreeNode(5);
		tree2.root.right = new TreeNode(6);
		tree2.root.left = new TreeNode(4);
		tree1.root = merge(tree1.root, tree2.root);
		display(tree1.root);
	}
	static void display(TreeNode root){
		if(root==null) return;
		String str = root.val+" L: ";
		str+=root.left==null?"null R: ":root.left.val+" R: ";
		str+=root.right==null?"null":root.right.val+"";
		System.out.println(str);
		display(root.left);
		display(root.right);

	}
	static TreeNode merge(TreeNode root1,TreeNode root2){
		if(root1==null) return root2;
		if(root2==null) return root1;
		ArrayList<Integer> r1 = new ArrayList<>();
		ArrayList<Integer> r2 = new ArrayList<>();
		fill(root1,r1);
		fill(root2,r2);
		ArrayList<Integer> arr= merge2Arrays(r1,r2);
		return make(arr,0,arr.size()-1);
	}
	static TreeNode make(ArrayList<Integer> arr, int i, int j){
		if(i>j) return null;
		int mid = i+(j-i)/2;
		TreeNode root = new TreeNode(arr.get(mid));
		root.left = make(arr, i, mid-1);
		root.right = make(arr, mid+1, j);
		return root;
	}
	static ArrayList<Integer> merge2Arrays(ArrayList<Integer> arr1, ArrayList<Integer> arr2){
		if(arr1.size()==0) return arr2;
		if(arr2.size()==0) return arr1;
		ArrayList<Integer> arr = new ArrayList<>();
		int i=0,j=0;
		while(i<arr1.size()-1 && j<arr2.size()-1){
			if(arr1.get(i)<arr2.get(j)){
				arr.add(arr1.get(i));
				i++;
			}else{
				arr.add(arr2.get(j));
				j++;
			}
		}
		while(i<arr1.size()){
			arr.add(arr1.get(i));
			i++;
		}
		while(j<arr2.size()){
			arr.add(arr2.get(j));
			j++;
		}
		return arr;
	}
	static void fill(TreeNode node,ArrayList<Integer> arr){
		if(node==null) return;
		fill(node.left, arr);
		arr.add(node.val);
		fill(node.right, arr);
	}

}
