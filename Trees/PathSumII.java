package Trees;

import java.util.ArrayList;
import java.util.List;

import Trees.BinaryTree.*;
public class PathSumII {
	public static void main(String[] args) {
		
	}
	static List<List<Integer>> list;
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        list = new ArrayList<>();
        if(root==null) return list;
        help(root,targetSum,new ArrayList<>() );
        return list;
    }
    private void help(TreeNode root, int targetSum,ArrayList<Integer> ans){
        //backtracking
        if(root==null) return;
        ans.add(root.val);
        if(root.left==null && root.right==null && targetSum==root.val){
            list.add(new ArrayList<>(ans));
            ans.remove(ans.size()-1);
            return;
        }
        targetSum-=root.val;
        help(root.left,targetSum,ans);
        help(root.right,targetSum,ans);
        
        
        ans.remove(ans.size()-1);
    }
}
