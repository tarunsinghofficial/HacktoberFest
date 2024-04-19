package Trees;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.PriorityQueue;
import Trees.BinaryTree.*;

class Point{
	int x;
	int y;
	TreeNode root;
	Point(int x,int y, TreeNode root){
		this.x = x;
		this.y = y;
		this.root = root;
	}
}

public class VerticalOrder {
	public static void main(String[] args) {
		
	}
	public List<List<Integer>> vertical(TreeNode root){
		List<List<Integer>>res  = new ArrayList<>();
		if(root==null) return res;
		Map<Integer,PriorityQueue<Point>> map = new HashMap<>();
		Queue<Point> queue = new LinkedList<>();
		queue.offer(new Point(0, 0, root));
		Comparator<Point> comparator = (a,b) ->{
			if(a.y==b.y){
				return a.root.val-b.root.val;
			}else{
				return a.y-b.y;
			}
		};
		int maxIdx = Integer.MIN_VALUE;
		int minIdx = Integer.MAX_VALUE;
		while(!queue.isEmpty()){
			Point point = queue.poll();
			root = point.root;
			map.putIfAbsent(point.x, new PriorityQueue<>(comparator));
			map.get(point.x).add(point);
			minIdx = Math.min(minIdx, point.x);
			maxIdx = Math.max(maxIdx, point.x);
			if(root.left!=null) queue.offer(new Point(point.x-1,point.y+1,point.root.left));
			if(root.right!=null) queue.offer(new Point(point.x+1, point.y+1, point.root.right));
		}
		for(int i=minIdx;i<=maxIdx;i++){
			PriorityQueue<Point> pq = map.get(i);
			List<Integer> list = new ArrayList<>();
			while(!pq.isEmpty()){
				list.add(pq.poll().root.val);
			}
			res.add(list);
		}
		return res;
	}
}
