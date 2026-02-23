#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;                   // store elements
    unordered_map<int, int> mp;         // value -> index

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val)) 
            return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;

        int index = mp[val];
        int lastElement = nums.back();

        // Move last element to deleted spot
        nums[index] = lastElement;
        mp[lastElement] = index;

        // Remove last
        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};