package Trees;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import Trees.BinaryTree.*;

public class TopView {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(1);
		tree.root.left = new TreeNode(2);
		tree.root.right = new TreeNode(3);
		tree.root.left.left = new TreeNode(4);
		tree.root.left.right = new TreeNode(5);
		tree.root.right.right = new TreeNode(7);
		tree.root.right.left = new TreeNode(6);
		System.out.println(top(tree.root));
	}
	static List<Integer> top(TreeNode root){
		List<Integer> ans = new ArrayList<>();
		if(root==null) return ans;
		Map<Integer,Integer> map = new HashMap<>();
		Queue<Point> queue = new LinkedList<>();
		queue.add(new Point(0, 0, root));
		int minIndex = Integer.MAX_VALUE;
		int maxIndex = Integer.MIN_VALUE;
		while(!queue.isEmpty()){
			Point p = queue.poll();
			map.putIfAbsent(p.x, p.root.val);
			minIndex = Math.min(minIndex,p.x);
			maxIndex = Math.max(maxIndex,p.x);
			if(p.root.left!=null) queue.add(new Point(p.x-1, p.y+1, p.root.left));
			if(p.root.right!=null) queue.add(new Point(p.x+1, p.y+1, p.root.right));
		}
		for(int i=minIndex;i<=maxIndex;i++){
			ans.add(map.get(i));
		}
		return ans;
		

	}
}
