package Trees;


import Trees.BinaryTree.*;
public class Merge2BSTOptimal {
	public static void main(String[] args) {
		BinaryTree tree1 = new BinaryTree();
		BinaryTree tree2 = new BinaryTree();
		tree1.root =new TreeNode(2);
		tree1.root.left =new TreeNode(1);
		tree1.root.right =new TreeNode(3);
		tree2.root = new TreeNode(5);
		tree2.root.right = new TreeNode(6);
		tree2.root.left = new TreeNode(4);
		tree1.root = merge(tree1.root, tree2.root);
	}
	static void display(TreeNode root){
		if(root==null) return;
		String str = root.val+" L: ";
		str+=root.left==null?"null R: ":root.left.val+" R: ";
		str+=root.right==null?"null":root.right.val+"";
		System.out.println(str);
		display(root.left);
		display(root.right);

	}
	static TreeNode merge(TreeNode root1,TreeNode root2){
		if(root1==null) return root2;
		if(root2==null) return root1;
		TreeNode head1 = BSTtoDLL(root1);
		TreeNode head2 = BSTtoDLL(root2);
		TreeNode node =  mergeTwoSortedLL(head1, head2);
		return convert(node);
	}
	static TreeNode convert(TreeNode root){
		if(root==null||(root.left==null && root.right==null)) return root;
		TreeNode mid = mid(root);
		TreeNode temp = mid.right;
		if(mid.left!=null){
			mid.left.right = null;
		}
		mid.left = null;
		if(mid.right!=null){
			mid.right.left = null;
		}
		mid.right = null;
		mid.left = convert(root);
		mid.right = convert(temp);
		return mid;
	}
	static TreeNode mid(TreeNode node){
		TreeNode slow = node;
		TreeNode fast = node;
		while(fast.right!=null && fast.right.right!=null){
			fast = fast.right.right;
			slow = slow.right;
		}
		return slow;

	}
	static TreeNode mergeTwoSortedLL(TreeNode node1, TreeNode node2){
		if(node1==null) return node2;
		if(node2==null) return node1;
		if(node1.val<node2.val){
			TreeNode n = mergeTwoSortedLL(node1.right, node2);
			n.left = node1;
			node1.right = n;
			// node1.left = null;
			return node1;
		}else{
			TreeNode n = mergeTwoSortedLL(node1, node2.right);
			n.left = node2;
			node2.right = n;
			// node1.left = null;
			return node2;
		}
	
	}
	static TreeNode head;
	static TreeNode prev;
	static TreeNode BSTtoDLL(TreeNode node){
		if(node==null) return null;
		head = null;
		prev = null;
		convert1(node);
		return head;
	}
	static void convert1(TreeNode node){
		if(node==null) return;
		convert1(node.left);
		if(prev==null){
			head = node;
		}else{
			prev.right = node;
			node.left = prev;
		}
		prev = node;
		convert1(node.right);
	}
}
