package Trees;

import java.util.ArrayList;
import java.util.Collections;

import Trees.BinaryTree.*;
public class RecoverBST {
	public static void main(String[] args) {
		
	}
	public void recoverTree(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        in(root,arr);
        Collections.sort(arr);
        root =  build(arr,0,arr.size()-1);
        System.out.println(root.val);
    }
    public void in(TreeNode root ,ArrayList<Integer> arr){
        if(root==null) return;
        in(root.left,arr);
        arr.add(root.val);
        in(root.right,arr);
    }
    public void sort(ArrayList<Integer> arr){
        for(int i=1;i<arr.size()-1;i++){
            int key = arr.get(i);
            int j = i-1;
            while(j>0 && arr.get(j)>key){
                arr.set((j+1) ,arr.get(j));
                j--;
            }
            arr.set(j,key);
        }
    }
    public TreeNode build(ArrayList<Integer> arr, int i, int j){
        if(i>j) return null;
        int mid = i+(j-i)/2;
        TreeNode root = new TreeNode(arr.get(mid));
        root.left = build(arr,i,mid-1);
        root.right = build(arr,mid+1,j);
        return root;
    }
}
