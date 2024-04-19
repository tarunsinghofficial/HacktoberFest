package Trees;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeMap;


import Trees.BinaryTree.*;
public class VerticalOrderSum {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
        root.left = (new TreeNode(2));
        root.right = (new TreeNode(3));
        root.left.left = (new TreeNode(4));
        root.left.right = (new TreeNode(5));
        root.right.left = (new TreeNode(6));
        root.right.right = (new TreeNode(7));
		sum(root);
	}
	static class Node {
		int x;
		TreeNode node;
		Node(int x,TreeNode node){
			this.x = x;
			this.node = node;
		}
	}
	static class Help implements Comparator<Node>{
		@Override
		public int compare(Node o1, Node o2) {
			return o1.x-o2.x;
		}
	}
	static void sum(TreeNode root){
		ArrayList<Integer> ans = new ArrayList<>();
		if(root==null) return ;
		Queue<Node> q = new LinkedList<>();
		TreeMap<Integer,Integer> map = new TreeMap<>();
		q.add(new Node(0,root));
		while(!q.isEmpty()){
			Node n = q.poll();
			if(map.containsKey(n.x)){
				map.put(n.x, map.get(n.x)+n.node.val);
			}else{
				map.put(n.x, n.node.val);
			}
			if(n.node.left!=null){
				q.add(new Node(n.x-1, n.node.left));
			}
			if(n.node.right!=null){
				q.add(new Node(n.x+1,n.node.right));
			}
		}
		for(int key:map.keySet()){
			ans.add(key);
		}
		for(int i=0;i<map.size();i++){
			ans.set(i, map.get(ans.get(i)));
		}
		System.out.println(ans);
	}
}
