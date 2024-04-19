package Trees;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import Trees.BinaryTree.*;
public class KDistanceAway {
	public static void main(String[] args) {
		
	}
	static List<Integer> distanceK(TreeNode root, TreeNode target, int k){
		List<Integer> res  = new ArrayList<>();
		if(root==null) return res;
		HashMap<TreeNode,TreeNode> parentMap = new HashMap<>();
		findParent(parentMap,root);
		Queue<TreeNode> queue = new LinkedList<>();
		HashSet<TreeNode> set = new HashSet<>();
		queue.add(target);
		while(!queue.isEmpty()){
			int size = queue.size();
			for(int i=0;i<size;i++){
				TreeNode curr = queue.poll();
				set.add(curr);
				if(k==0){
					res.add(curr.val);
				}
				if(parentMap.containsKey(curr) && !set.contains(parentMap.get(curr))){
					queue.add(parentMap.get(curr));
				}
				if(curr.left!=null && !set.contains(curr.left)){
					queue.add(curr.left);
				}
				if(curr.right!=null && !set.contains(curr.right)){
					queue.add(curr.right);
				}
			}
			k--;
			if(k<0) break;

		}
		return res;
	} 
	static void findParent(HashMap<TreeNode,TreeNode> map,TreeNode root){
		if(root==null) return;
		if(root.left!=null) map.put(root.left, root);
		if(root.right!=null) map.put(root.right, root);
		findParent(map, root.left);
		findParent(map, root.right);
		
	}
}
