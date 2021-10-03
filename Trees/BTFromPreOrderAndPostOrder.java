package Trees;

import Trees.BinaryTree.*;
public class BTFromPreOrderAndPostOrder {
	public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return help(pre,post,0,pre.length-1,0,post.length-1);
    }
    public TreeNode help(int[] pre, int[] post, int s1, int e1, int s2, int e2){
       if(s1>e1) return null;
        TreeNode root = new TreeNode(pre[s1]);
        if(s1==e1) return root;
        int idx = s2;
        while(post[idx]!=pre[s1+1]){
            idx++;
        }
        int k = idx-s2+1;
        root.left = help(pre,post,s1+1,s1+k,s2,idx);
        root.right = help(pre,post,s1+k+1,e1,idx+1,e2-1);
        return root;
        
    }
}
