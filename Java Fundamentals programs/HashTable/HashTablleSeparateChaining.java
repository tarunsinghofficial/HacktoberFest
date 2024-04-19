package HashTable;

public class HashTablleSeparateChaining implements Map {
    List[] entries;
    int size;
    private static class Node{
        Node next,pre;
        Entry data;
        Node(Entry data, Node next, Node pre){
            this.data=data;
            this.next=next;
            this.pre=pre;
        }
    }
    private static class Entry{
        Object key;
        Object value;
        Entry(Object key, Object value){
            this.key=key;
            this.value=value;
        }
    }
    private static class List{
        Node start,end;
        List(){
            start=end=null;
        }
    }
    public HashTablleSeparateChaining(int capacity){
        entries=new List[capacity];
    }
    public HashTablleSeparateChaining(){
        this(50);
    }
    public int hash(Object key){
        return (key.hashCode()&0xFFFFFFF)%entries.length;
    }
    public int size(){
        return size;
    }
    @Override
    public boolean put(Object key, Object value){
       if(entries.length==size)
           rehash();
        int pos=hash(key);
        if(entries[pos]==null){
            entries[pos]=new List();
            entries[pos].start=entries[pos].end=new Node(new Entry(key,value),null,null);
            size++;
            return true;
        }
        else{
            entries[pos].end.next=new Node(new Entry(key,value),null,entries[pos].end);
            entries[pos].end=entries[pos].end.next;
            size++;
            return true;
        }
    }
    @Override
    public Object get(Object key){
        if(size==0)
            throw new IllegalStateException("Table is empty");
        int pos=hash(key);
        if(entries[pos]!=null){
            for(Node a=entries[pos].start; a!=null; a=a.next){
                if(a.data.key.equals(key))
                    return a.data.value;
            }
        }
        return null;
    }
    @Override
    public Object remove(Object key){
        if(size==0)
            throw new IllegalStateException("Table is Empty");
        int pos=hash(key);
        if(entries[pos]!=null){
            for(Node a=entries[pos].start; a!=null; a=a.next){
               if(a.data.key.equals(key)){
                   Object v=a.data.value;
                   if(a.pre!=null) a.pre.next=a.next;
                   if(a.next!=null) a.next.pre=a.pre;
                   if(a==entries[pos].start) entries[pos].start=a.next;
                   if(a==entries[pos].end) entries[pos].end=a.pre;
                   size--;
                   return v;
               }                    
            }
        }
        return null;
    }
    
    public void rehash(){
        size=0;
        List[] oldEntries=entries;
        entries=new List[(oldEntries.length*2)+1];
        for(int i=0; i<oldEntries.length; i++){
            if(oldEntries[i]==null) continue;
            for(Node a=oldEntries[i].start; a!=null; a=a.next){
                int pos=hash(a.data.key);
                if(entries[pos]==null){
                    entries[pos]=new List();
                    entries[pos].start=entries[pos].end=new Node(new Entry(a.data.key,a.data.value), null, null);
                    size++;
                }
                else{
                    entries[pos].end.next=new Node(new Entry(a.data.key,a.data.value), null, entries[pos].end);
                    entries[pos].end=entries[pos].end.next;
                    size++;
                }
            }
        }
    }
    public String toString(){
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<entries.length; i++){
            if(entries[i]==null) continue;
            for(Node a=entries[i].start; a!=null; a=a.next){
                sb.append("[ ").append(a.data.key).append(" : ").append(a.data.value).append("]\n");
        }
    }
      return sb.toString();
    }
    public static void main(String args[]){
        HashTablleSeparateChaining books = new HashTablleSeparateChaining();
        books.put("PK", "Pakistan");
        books.put("IND", "India");
        books.put("BN", "Bangladesh");
        books.put("USA", "United States");
        System.out.println(books.remove("USA"));
        System.out.println(books);
        System.out.println(books.size());
    }
}
