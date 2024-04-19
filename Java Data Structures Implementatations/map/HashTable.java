/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package map;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class HashTable implements Map {

private Entry[] entries;
private int size, used;
private final Entry NIL = new Entry(null, null);
private float loadFactor;

private class Entry {

Object key, value;

public Entry(Object key, Object value) {
    this.key = key;
    this.value = value;
}
}

public HashTable(int capacity, float loadFactor) {
    entries = new Entry[capacity];
    this.loadFactor = loadFactor;
}

public HashTable(int capacity) {
    this(capacity, 0.75F);
}

public HashTable() {
    this(101);
}

public int hash(Object key) {
    if (key == null) {
        throw new IllegalStateException();
    }
    return (key.hashCode() & 0x7FFFFFFF) % entries.length;
}

@Override
public Object put(Object key, Object value) {
    if (used > loadFactor * entries.length) {
        reHash();
    }
    int h = hash(key);
    for (int i = 0; i < entries.length; i++) {
        int k = nextProbe(h, i);  //finding next empty space to put our data
        if (entries[k] == null) {
            entries[k] = new Entry(key, value);
            ++size;
            ++used;
            return null;
        }
    }
    throw new IllegalStateException();   //table overflow
}


public int nextProbe(int hashedIndex, int loopVariable) {
    return (hashedIndex + loopVariable) % entries.length;
}

@Override
public Object get(Object key) {
    int h = hash(key);
    System.out.println("The key for " + key + " is " + h);
    for (int i = 0; i < entries.length; i++) {
        int k = nextProbe(h, i);
        if (entries[k] == null) {
            break;                  //means linear probing is not applied
        }
        if (entries[k] == NIL) {      //means  current element has no data skip this iteration
            continue;
        }
        if (entries[k].key.equals(key)) {
            return entries[k].value;
        }

    }
    return "Value not found!";
}

@Override
public Object remove(Object key) {
    int h = hash(key);
    for (int i = 0; i < entries.length; i++) {
        int j = nextProbe(h, i);      //finding next probe
        if (entries[j] == null) {
            break;
        }
        if (entries[j] == NIL) {
            continue;
        }
        if (entries[j].key.equals(key)) {
            Object value = entries[j].value;
            entries[j] = NIL;
            --size;
            return value;
        }
    }
    return "Value not found!";
}

public void reHash() {
    Entry[] oldEntries = entries;
    entries = new Entry[2 * oldEntries.length + 1];     //+1  make it  odd number as even number causes max linear probing.
    for (int i = 0; i < oldEntries.length; i++) {
        Entry entry = oldEntries[i];
        if (entry == null || entry == NIL) {
            continue;
        }
        int h = hash(entry.key);
        for (int j = 0; j < entries.length; j++) {
            int k = nextProbe(h, j);
            if (entries[k] == null) {
                entries[k] = entry;
                break;
            }
        }

    }
    used = size;
}

@Override
public int size() {
    return size;
}

public void printAllTables() {
    for (int i = 0; i < entries.length; i++) {
        if (entries[i] != null) {
            System.out.println(i + " " + entries[i].key + " has value " + entries[i].value);
        } else {
            System.out.println(i + " is empty.");
        }
    }
}

public static void main(String[] args) {
    CountryTable[] countries = new CountryTable[6];
    countries[0] = new CountryTable("Pakistan", "Urdu", 33, 222222222);
    countries[1] = new CountryTable("Portugal", "Portugese", 33, 222222222);
    countries[2] = new CountryTable("India", "Hindi", 33, 222222222);
    countries[3] = new CountryTable("Japan", "Japanese", 33, 222222222);
    countries[4] = new CountryTable("Australia", "English", 33, 222222222);
    countries[5] = new CountryTable("Sweden", "Swedish", 33, 222222222);
    HashTable table = new HashTable(9,0.5f);
    table.put("PK", countries[0]);
    table.put("PT", countries[1]);
    table.put("IT", countries[2]);
    table.put("AT", countries[3]);
    table.put("DE", countries[4]);
    table.put("SE", countries[5]);
    table.put("GB", new CountryTable("United Kingdom", "English", 33, 222222222));
    table.remove("GB");
    table.printAllTables();
    System.out.println(table.get("GB"));
}

}
