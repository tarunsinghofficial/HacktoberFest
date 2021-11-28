package Trees;

import Trees.BinaryTree.*;
public class BSTFromPreOrder {
	public TreeNode bstFromPreorder(int[] pre) {
        return help(pre,0,pre.length-1);
    }
    static TreeNode help(int[] pre, int start, int end){
        if(start>end) return null;
        TreeNode root = new TreeNode(pre[start]);
        if(start==end) return root;
        int idx = start;
        while(idx< pre.length && pre[start]>=pre[idx]){
            idx++;
        }
        int k = idx-start;
        root.left = help(pre,start+1,start+k-1);
        root.right = help(pre,start+k,end);
        return root;
        
    }
}
