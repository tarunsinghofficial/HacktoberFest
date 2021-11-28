package Trees;

import java.util.ArrayList;
import java.util.Collections;

import Trees.BinaryTree.*;
public class MinDistBwNodes {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(2);
		tree.root.left = new TreeNode(1);
		tree.root.right = new TreeNode(3);
		// tree.root.right.left = new TreeNode(14);
		// tree.root.right.right = new TreeNode(15);
		// tree.root.right.left.left = new TreeNode(21);
		// tree.root.right.left.right = new TreeNode(24);
		// tree.root.right.right.left = new TreeNode(22);
		// tree.root.right.right.right = new TreeNode(23);
		System.out.println(findDist(tree.root, 1, 3));
	}
	static int findDist(TreeNode root, int a, int b) {
        // Your code here
        ArrayList<Integer> a1 = fill(root,a);
        ArrayList<Integer> a2 = fill(root,b);
        Collections.reverse(a1);
        Collections.reverse(a2);
        int j=0;
        while(j<a1.size()-1 && j<a2.size()-1){
            if(a1.get(j)!=a2.get(j)) break;
            j++;
        }
        return ++j;
        
    }
    // static TreeNode find(TreeNode root, int data){
    //     if(root==null) return null;
    //     if(root.val==data) return root;
    //     TreeNode l = find(root.left,data);
    //     TreeNode r = find(root.right, data);
    //     return l==null?r:l;
    // }
    static ArrayList<Integer> fill(TreeNode root, int data){
        if(root==null) return new ArrayList<>();
        if(root.val==data){
            ArrayList<Integer> arr = new ArrayList<>();
            arr.add(root.val);
            return arr;
        }
        ArrayList<Integer> l = fill(root.left,data);
        ArrayList<Integer> r = fill(root.right,data);
        if(!l.isEmpty()){
            l.add(root.val);
            return l;
        }
        if(!r.isEmpty()){
            r.add(root.val);
            return r;
        }
        return new ArrayList<>();
    }
}
