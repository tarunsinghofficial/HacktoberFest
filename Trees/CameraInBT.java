package Trees;

import Trees.BinaryTree.*;
public class CameraInBT {
	public static void main(String[] args) {
		
	}
	static int camera = 0;
	static int camera(TreeNode root){
		if(help(root)==-1) camera++;
		return camera; 
	}
	// 0 -> has camera
	// 1-> is Covered
	// -1-> needs to be covered
	static int help(TreeNode root){
		if(root==null) return 1;
		int l = help(root.left);
		int r = help(root.right);
		if(l==-1||r==-1){
			camera++;
			return 0;
		}
		if(l==0||r==0){
			return 1;
		}
		return -1;
	}
	
}
