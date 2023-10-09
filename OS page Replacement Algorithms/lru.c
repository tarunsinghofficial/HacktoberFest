#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // Move the accessed item to the front of the list
            moveToFront(key);
            return cache[key];
        }
        return -1; // Page not found in cache
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If the key already exists, update the value and move to the front
            cache[key] = value;
            moveToFront(key);
        } else {
            // If the cache is at its capacity, remove the least recently used item
            if (cache.size() >= capacity) {
                int lruKey = lruList.back();
                lruList.pop_back();
                cache.erase(lruKey);
            }
            // Add the new item to the front of the list and cache
            lruList.push_front(key);
            cache[key] = value;
        }
    }

private:
    int capacity;
    list<int> lruList;
    unordered_map<int, int> cache;

    // Helper function to move a key to the front of the list
    void moveToFront(int key) {
        lruList.remove(key);
        lruList.push_front(key);
    }
};

int main() {
    // Create an LRU cache with a capacity of 3
    LRUCache cache(3);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);

    cout << cache.get(1) << endl; // Output: 1 (Page 1 is in cache)
    cout << cache.get(2) << endl; // Output: 2 (Page 2 is in cache)

    cache.put(4, 4); // Replace page 3 with page 4

    cout << cache.get(3) << endl; // Output: -1 (Page 3 was replaced and is not in cache)
    
    return 0;
}
