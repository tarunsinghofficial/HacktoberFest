package Trees;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class DesignALeaderBoard {
	Map<Integer,Integer> map;
	PriorityQueue<Player> pq;
	class Player implements Comparable<Player>{
		int id;
		int score;
		Player(int id, int score){
			this.id = id;
			this.score = score;
		}
		public int compareTo(Player p){
			return Integer.compare(p.score, this.score);
		}
	}
	public DesignALeaderBoard() {
		map = new HashMap<>();
		pq = new PriorityQueue<>(Collections.reverseOrder());
	}
	public void addScore(int playerId, int score) { 
		map.putIfAbsent(playerId, 0);
		map.put(playerId, score);
		pq.offer(new Player(playerId, score));
	}
	public int top(int k) {
		ArrayList<Player> temp = new ArrayList<>();
		int ans = 0;
		for(int i=0;i<k;i++){
			Player p = pq.poll();
			ans+=p.score;
			temp.add(p);
		}
		for(Player p:temp) pq.offer(p);
		return ans;
	}
	public void reset(int playerId) {
		int score = map.get(playerId);
		pq.remove(new Player(playerId, score));
		map.put(playerId, 0);
		pq.add(new Player(playerId, 0));

	}
}
