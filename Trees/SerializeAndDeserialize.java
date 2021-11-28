package Trees;

import Trees.BinaryTree.TreeNode;

public class SerializeAndDeserialize {
	static String ans ="";
    public String serialize(TreeNode root) {
        help(root);
        System.out.println(ans);
        return ans;
    }
    private void help(TreeNode root){
        if(root==null){
            ans+="*";
            return;
        }
        ans+=root.val+"";
        help(root.left);
        help(root.right);
        
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
//     4-7**-3-9960*-1**6-4****-7-65***-69-2****-3-4***
       if(i>=data.length()) return null;
        if(data.charAt(i)=='*'){
            i+=1;
            return null;
        }
        TreeNode root;
        if(data.charAt(i)=='-'){
             root = new TreeNode((data.charAt(i+1)-'0')*-1);
            i+=2;
        }else{
             root = new TreeNode(data.charAt(i)-'0');
            i+=1;
        }
        
        root.left = deserialize(data);
        root.right = deserialize(data);
        return root;
    }
    static int i =0;	
}
