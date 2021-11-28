package Trees;

import Trees.BinaryTree.*;
public class BTFromLevelOrderAndInOrder {
	public static void main(String[] args) {
		int[] in = { 4, 2, 5, 1, 6, 3, 7 };
		int[] lo = { 1, 2, 3, 4, 5, 6, 7 };
		BinaryTree tree = new BinaryTree();
		tree.root = build(in, 0, in.length-1, lo, 0, lo.length-1);
		BinaryTree.display(tree.root);
	}
	static TreeNode build(int[] in, int inStart, int inEnd, int[] level, int lStart, int lEnd){
		if(inStart>inEnd||lStart>level.length-1)return null;
		TreeNode root = new TreeNode(level[lStart]);
		if(inStart==inEnd) return root;
		int idx = inStart;
		while(level[lStart]!=in[idx]){
			idx++;
		}
		int k = idx-inStart;
		root.left = build(in, inStart, inStart+k-1, level, 2*lStart+1, lEnd);
		root.right = build(in, inStart+k+1, inEnd, level, 2*lStart+2, lEnd);
		return root;
	}
}
