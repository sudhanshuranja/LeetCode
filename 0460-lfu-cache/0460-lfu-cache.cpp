#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, pair<int,int>> keyValueFreq; 
    // key -> {value, freq}

    unordered_map<int, list<int>> freqList; 
    // freq -> list of keys (LRU order)

    unordered_map<int, list<int>::iterator> keyIterator;
    // key -> iterator in freq list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValueFreq.find(key) == keyValueFreq.end())
            return -1;

        updateFrequency(key);
        return keyValueFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyValueFreq.find(key) != keyValueFreq.end()) {
            keyValueFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        if (keyValueFreq.size() == capacity) {
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValueFreq.erase(keyToRemove);
            keyIterator.erase(keyToRemove);
        }

        keyValueFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIterator[key] = freqList[1].begin();
        minFreq = 1;
    }

private:
    void updateFrequency(int key) {
        int freq = keyValueFreq[key].second;

        freqList[freq].erase(keyIterator[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyValueFreq[key].second++;
        freqList[freq + 1].push_front(key);
        keyIterator[key] = freqList[freq + 1].begin();
    }
};