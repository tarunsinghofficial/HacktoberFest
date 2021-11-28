package Trees;

import java.util.HashMap;

class Node{
	int key;
	Node left;
	Node right;
	Node random;
	Node(int key){
		this.key = key;
		left = right = random = null;
	}
}
public class CloneTreeWithARandomPointer {
	public static void main(String[] args) {
		
	}
	static Node cloneTree(Node root){
		HashMap<Node,Node> map = new HashMap<>();
		Node cloneNode = cloneLR(root, map);
		cloneRandom(root, cloneNode, map);
		return cloneNode;
	}
	static Node cloneLR(Node node, HashMap<Node,Node> map){
		if(node==null) return null;
		Node cloneNode = new Node(node.key);
		map.put(node, cloneNode);
		cloneNode.left = cloneLR(node.left,map);
		cloneNode.right = cloneLR(node.right,map);
		return cloneNode;

	}
	static void cloneRandom(Node node, Node cloneNode, HashMap<Node,Node> map){
		if(node==null) return;
		cloneNode.random = map.get(node).random;
		cloneRandom(node.left, cloneNode.left, map);
		cloneRandom(node.right,cloneNode.right,map);
	}
}
