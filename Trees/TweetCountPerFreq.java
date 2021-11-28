package Trees;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
public class TweetCountPerFreq {
	private Map<String, TreeMap<Integer,Integer>> record;
	public TweetCountPerFreq(){
		record = new HashMap<>();
	}
	public void recordTweet(String tweetName, int time){
		record.putIfAbsent(tweetName, new TreeMap<Integer,Integer>());
		TreeMap<Integer,Integer> tm = record.get(tweetName);
		tm.put(time, tm.getOrDefault(time, 0)+1);
	}
	public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime){
		int split = 60;
		if(freq.equals("hour")) split = 60*60;
		if(freq.equals("day")) split = 60*60*24;
		List<Integer> res = new ArrayList<>();
		TreeMap<Integer, Integer> tm = record.get(tweetName);
		if(!record.containsKey(tweetName)) return res;
		for(int start = startTime;start<=endTime;start+=split){
			int count = 0;
			int end = Math.min(endTime+1,start+split);
			Map<Integer,Integer> sub = tm.subMap(start,end);
			for(int val:sub.values()){
				count+=val;
			}
			res.add(count);
		}
		return res;
	}
}
