#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> mp;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (!mp.count(value)) return 0;

        vector<int>& indices = mp[value];

        auto l = lower_bound(indices.begin(), indices.end(), left);
        auto r = upper_bound(indices.begin(), indices.end(), right);

        return r - l;
    }
};



/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */