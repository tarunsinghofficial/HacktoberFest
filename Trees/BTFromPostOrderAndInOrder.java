package Trees;

import Trees.BinaryTree.*;
public class BTFromPostOrderAndInOrder {
	public static void main(String[] args) {
		int[] pre = {9,15,7,20,3};
		int[] in = {9,3,15,20,7};
		BinaryTree tree = new BinaryTree();
		tree.root = build(in, pre, 0, in.length-1,0, pre.length-1);
		BinaryTree.display(tree.root);
	}
	static TreeNode build(int[] in, int[] post, int inStart, int inEnd,int pStart,int pEnd){
		if(pStart>pEnd || inStart>inEnd) return null;
		TreeNode root = new TreeNode(post[pEnd]);
		int i = find(in, inStart, inEnd, post[pEnd]);
		root.left = build(in, post, inStart, i-1, pStart,pStart+i-inStart-1);
		root.right = build(in, post, i+1, inEnd, pStart+i -inStart,pEnd-1);
		return root;
	}
	static int find(int[] in, int inStart, int inEnd,int ele){
		for(int i=inStart;i<=inEnd;i++){
			if(in[i]==ele) return i;
		}
		return -1;
	}
}
