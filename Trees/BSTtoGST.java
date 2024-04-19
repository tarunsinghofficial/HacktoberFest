package Trees;

import Trees.BinaryTree.*;
public class BSTtoGST {
	int sum = 0;
    public TreeNode bstToGst(TreeNode root){
        if(root==null){
            return null;
        }
        bstToGst(root.right);
        root.val +=sum;
        sum = root.val;
        bstToGst(root.left);
        return root;
    }

}
