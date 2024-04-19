package HashTable;
public interface Map {
    public boolean put(Object key, Object value);
    public Object get(Object key);
    public Object remove(Object key);
    public int size();
}
