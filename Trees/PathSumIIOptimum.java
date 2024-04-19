package Trees;

import java.util.HashMap;

import Trees.BinaryTree.*;
public class PathSumIIOptimum {
	// O(n) approach
	// Associate with target sum in array
	int count = 0;
	public int pathSum(TreeNode root, int sum){
		if(root==null) return 0;
		HashMap<Integer,Integer> map = new HashMap<>();
		map.put(0, 1);
		findPathSum(root,0,sum,map);
		return count;
	}
	private void findPathSum(TreeNode root, int currSum, int sum, HashMap<Integer,Integer> map){
		if(root==null) return;
		currSum+= root.val;
		if(map.containsKey(currSum-sum)){
			count+= map.get(currSum-sum);
		}
		map.put(currSum, map.getOrDefault(currSum, 1)+1);//increase the frequency OR add
		findPathSum(root.left, currSum, sum, map);
		findPathSum(root.right, currSum, sum, map);
		map.put(currSum, map.get(currSum)-1);//remove it back on the go
		return;
	}


}
