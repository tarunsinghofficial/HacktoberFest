package Trees;

import Trees.BinaryTree.*;
// O(n^2)
public class PathSumIII {
	int count = 0;
	public int pathSum(TreeNode root, int sum){
		findPathSum(root, sum, 0);
		pathSum(root.left, sum);
		pathSum(root.right, sum);
		return count;
	}
	void findPathSum(TreeNode root, int sum, int currSum){
		if(root==null) return;
		currSum+= root.val;
		if(sum==currSum) count++;
		findPathSum(root.left, sum, currSum);
		findPathSum(root.right, sum, currSum);
	}

}
