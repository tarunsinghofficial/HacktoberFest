package HashTable;
import java.util.Hashtable;

public class HashTable {
    private Entry[] entries ;
    private int size;
    Entry NIL = new Entry();
    
    private class Entry{
        Object key;
        Object value;
        public Entry(){
            key=value=null;
        }
        public Entry(Object key, Object value){
            this.key=key;
            this.value=value;
        }
    }
    public HashTable(int capacity){
        entries=new Entry[capacity];
    }
    
    public int hash(Object key){
        return (key.hashCode() & 0xFFFFFFF)%entries.length;
    }
    
    public boolean put(Object key, Object value){
       if(entries.length==size) rehash();
        int h=hash(key);
        for (int i=0; i<entries.length; i++){
            int pos=(h+i)%entries.length;
            if(entries[pos]==null ||entries[pos]==NIL){
                entries[pos]= new Entry(key,value);
                size++;
                return true;
            }
                
        }
        return false;
    }
    public Object get(Object key){
        if(size==0) throw new IllegalStateException("Table is Empty");
        int h=hash(key);
        for (int i=0; i<entries.length; i++){
            int pos = (h+i)%entries.length;
            if(entries[pos]==null)
                break;
            if(entries[pos]==NIL)
                continue;
            if(entries[pos].key.equals(key)){
                return entries[pos].value;
            }
                        
        }
        return null;
    }
    public Object remove(Object key){
        if (size==0)
            throw new IllegalStateException("Table is Empty");
        int h=hash(key);
        for(int i=0; i<entries.length; i++){
            int pos = (h+i)%entries.length;
            if(entries[pos]==null)
                break;
            if(entries[pos]==NIL)
                continue;
            if(entries[pos].key.equals(key)){
                Object v = entries[pos].value;
                entries[pos]=NIL;
                size--;
                return v;
            }
        }
        return null;
    }
    public int size(){
        return size;
    }
    public int quadraticProb(int key, int i){
        return (key + i*i)% entries.length;
    }
    public void rehash(){
        this.size=0;
        Entry oldEntries[]=entries;
        entries=new Entry[(oldEntries.length*2)+1];  
// here we add extra 1 to make length a odd number bcoz there are less chances of collision in odd number
        for(int i=0; i<oldEntries.length; i++){
            if(oldEntries[i]==null || oldEntries[i]==NIL)
                continue;
            int h=hash(oldEntries[i].key);
            for(int j=0; j<entries.length; j++){
                int pos=(h+j)%entries.length;
                if(entries[pos]==null){
                    entries[pos]=oldEntries[i];
                    size++;
                    break;
                }
                
            }
            
        }
    }
    @Override
    public String toString(){
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<entries.length; i++){
            if(entries[i]==null || entries[i]==NIL)
                continue;
            sb.append("[").append(i).append(": ").append(entries[i].key).append(" - ").append(entries[i].value).append("]\n");
                    
        }
        return sb.toString();
    }
    
    public static void main(String[] args){
        HashTable books = new HashTable(3);
        books.put("c++", "Robert Lafore");
        books.put("java", "Shaurab Shukla");
        books.put("python", "Code With Harry");
        
        System.out.println(books);
        System.out.println(books.get("python"));
       // System.out.println(books.remove("java"));
        System.out.println(books);
        System.out.println(books.size());
        books.put("dart", "milton");
        System.out.println(books.size());
    }
}
