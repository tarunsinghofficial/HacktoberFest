package Trees;

import Trees.BinaryTree.BinaryTree;
import Trees.BinaryTree.TreeNode;

public class BTFromPreOrderAndInOrder {
	public static void main(String[] args) {
		int[] pre = {3,9,20,15,7};
		int[] in = {9,3,15,20,7};
		BinaryTree tree = new BinaryTree();
		tree.root = build(in, pre, 0, in.length-1, 0,pre.length-1);
		BinaryTree.display(tree.root);
	}
	static TreeNode build(int[] in, int[] pre, int inStart, int inEnd ,int pStart,int pEnd){
		if(inStart>inEnd) return null;
		TreeNode root = new TreeNode(pre[pStart]);
		int i = find(in, inStart, inEnd,pre[pStart]);
		root.left = build(in, pre, inStart, i-1, pStart+1,pEnd+(i-inStart));
		root.right = build(in, pre, i+1, inEnd, pStart+(i-inStart)+1,pEnd);
		return root;
	}
	static int find(int[] in, int inStart, int inEnd,int ele){
		for(int i=inStart;i<=inEnd;i++){
			if(in[i]==ele) return i;
		}
		return -1;
	}
}
