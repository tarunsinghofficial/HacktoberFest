package Trees;

import java.util.HashMap;

class Entry{
	int value;
	int key;
	Entry left;
	Entry right;
}
public class LeastRecentlyUsedCache {
	HashMap<Integer,Entry> map;
	Entry start,end;
	int LRU_SIZE;
	public LeastRecentlyUsedCache(){
		map = new HashMap<>();
		LRU_SIZE = 4;
	}
	public int getEntry(int key){
		if(map.containsKey(key)){
			Entry entry = map.get(key);
			removeNode(entry);
			addAtTop(entry);
			return entry.value;
		}
		return -1;
	}
	public void putEntry(int key, int value){
		if(map.containsKey(key)){
			Entry entry = map.get(key);
			entry.value = value;
			removeNode(entry);
			addAtTop(entry);
		}else{
			Entry node = new Entry();
			node.left = null;
			node.right = null;
			node.key = key;
			node.value = value;
			if(map.size()>LRU_SIZE){
				map.remove(end.key);
				removeNode(end);
			}
			addAtTop(node);
			map.put(key, node);
		}
	}
	private void addAtTop(Entry node){
		node.right = start;
		node.left = null;
		if(start!=null){
			start.left = node;
		}
		start= node;
		if(end==null){
			end = start;
		}
	}
	private void removeNode(Entry node){
		if(node.left!=null){
			node.left.right = node.right;
		}else{
			start = node.right;
		}
		if(node.right!=null){
			node.right.left = node.left;
		}else{
			end = node.left;
		}
	}

}
