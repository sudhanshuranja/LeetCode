#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;  // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move accessed node to front
        auto node = mp[key];
        int value = node->second;
        cache.erase(node);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Remove old node
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity) {
            // Remove least recently used
            auto lru = cache.back();
            mp.erase(lru.first);
            cache.pop_back();
        }

        // Insert new node at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};