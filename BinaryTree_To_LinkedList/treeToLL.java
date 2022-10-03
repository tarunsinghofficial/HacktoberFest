package BinaryTree_To_LinkedList;

class treeToLL {
    void preOrder(TreeNode root){
        if(root==null){
            return;
        }
        preOrder(root.left);
        preOrder(root.right);
        TreeNode left=root.left;
        TreeNode right=root.right;
        root.left=null;
        root.right=left;
        TreeNode p=root;
        while(p.right!=null){
            p=p.right;
        }
        p.right=right;   
    }
    public void flatten(TreeNode root) {
        preOrder(root);
    }
}

