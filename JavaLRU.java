import java.util.*;
public class JavaLRU {
    public static void main(String args[]) {
        LRUCache c = new LRUCache(3);
        c.addValue(1);
        c.addValue(2);
        c.addValue(3);
        c.look(1);
        c.addValue(4);
        c.look(2);
        c.addValue(5);
        c.print();
    }
}

class LRUCache{
    Set<Integer> store;
    int cap;
    
    public LRUCache(int cap){
        this.store= new LinkedHashSet<>(cap);// maintains insertion order
        this.cap =cap;
    }
    
    public void look(int key){
        if(store.contains(key)){
            store.remove(key);
            store.add(key);
        }
    }
    
    public void addValue(int key){
        if(!store.contains(key)){// chance of overflow
            if(store.size()==cap){
                //remove first element
                int val = store.iterator().next();
                store.remove(val);
            }
        }else{
            //remove current element
            store.remove(key);
        }
        store.add(key);
    }
    
    public void print(){
        store.forEach(e->{
            System.out.println(e);
        });
    }
}
