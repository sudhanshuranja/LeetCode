#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = mp[val].empty();

        nums.push_back(val);
        mp[val].insert(nums.size() - 1);

        return notPresent;
    }

    bool remove(int val) {
        if (mp[val].empty())
            return false;

        // Get one index of val
        int index = *mp[val].begin();
        mp[val].erase(index);

        int lastElement = nums.back();
        int lastIndex = nums.size() - 1;

        // Move last element to removed index
        nums[index] = lastElement;

        // Update lastElement's index set
        mp[lastElement].insert(index);
        mp[lastElement].erase(lastIndex);

        // Remove last element
        nums.pop_back();

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};