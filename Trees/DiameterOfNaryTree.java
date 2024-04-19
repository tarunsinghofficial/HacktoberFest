package Trees;

import java.util.ArrayList;

public class DiameterOfNaryTree {
	static class Node{
		int data;
		ArrayList<Node> child;
		Node(int data){
			this.data= data;
			child = new ArrayList<>();
		}
	}
	public static void main(String[] args) {
		
	}
	static int dia = 0;
	static int l = 0;
	static int sl = 0;
	public int dia(Node root){
		if(root==null) return 0;
		int max = 0;
		for(Node child:root.child){
			int h = dia(child);
			max = Math.max(max, h);
			if(h>=l){
				sl = l;
				l = h;
			}
			else if(h>sl){
				sl = h;
			}
		}
		if(dia>l+sl+2){
			dia = l+sl+2;
		}
		return max+1;
	}


}
