package Trees;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import Trees.BinaryTree.*;
public class DiagonalOrderII {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(6);
        root.right.right = new TreeNode(14);
        root.right.right.left = new TreeNode(13);
        root.left.right.left = new TreeNode(4);
        root.left.right.right = new TreeNode(7);
		List<List<Integer>> ans = travel(root);
		for(List<Integer> l:ans){
			System.out.println(l);
		}
	}
	static List<List<Integer>> travel(TreeNode root){
		List<List<Integer>> list = new ArrayList<>();
		if(root==null) return list;
		LinkedList<TreeNode> q = new LinkedList<>();
		q.addLast(root);
		while(!q.isEmpty()){
			int size = q.size();
			List<Integer> l = new ArrayList<>();
			while(size>0){
				TreeNode node = q.poll();
				while(node!=null){
					l.add(node.val);
					if(node.right!=null){
						q.addLast(node.right);
					}
					node = node.left;
				}
				size-=1;
			}
			
			list.add(l);
		}
		return list;
	}
}
