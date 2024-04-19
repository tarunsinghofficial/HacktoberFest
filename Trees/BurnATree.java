package Trees;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

import Trees.BinaryTree.*;
public class BurnATree {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(12);
		tree.root.left = new TreeNode(13);
		tree.root.right = new TreeNode(10);
		tree.root.right.left = new TreeNode(14);
		tree.root.right.right = new TreeNode(15);
		tree.root.right.left.left = new TreeNode(21);
		tree.root.right.left.right = new TreeNode(24);
		tree.root.right.right.left = new TreeNode(22);
		tree.root.right.right.right = new TreeNode(23);
		TreeNode node = find(tree.root, 14);
		find(tree.root, node);
	}
	static TreeNode find(TreeNode root, int data){
		if(root==null) return null;
		if(root.val == data) return root;
		TreeNode l = find(root.left, data);
		TreeNode r = find(root.right, data);
		return l==null?r:l;
	}
	static void find(TreeNode root, TreeNode node){
		if(root==null) return;
		HashMap<TreeNode, TreeNode> map = new HashMap<>();
		findParent(map, root);
		HashSet<TreeNode> set = new HashSet<>();
		Queue<TreeNode> q = new LinkedList<>();
		q.add(node);
		q.add(null);
		while(!q.isEmpty()){
			TreeNode n = q.poll();
			if(n==null){
				System.out.println();
				if(!q.isEmpty()) q.add(null);
			}
			else{
				System.out.print(n.val+" ");
				set.add(n);
				if(n.left!=null && !set.contains(n.left)){
					q.add(n.left);
				}
				if(n.right!=null && !set.contains(n.right)){
					q.add(n.right);
				}
				if(map.containsKey(n) && !set.contains(map.get(n))){
					q.add(map.get(n));
				}
			}
		}
	}
	static void findParent(HashMap<TreeNode,TreeNode> map,TreeNode root){
		if(root==null) return;
		if(root.left!=null) map.put(root.left, root);
		if(root.right!=null) map.put(root.right, root);
		findParent(map, root.left);
		findParent(map, root.right);
		
	}
}
