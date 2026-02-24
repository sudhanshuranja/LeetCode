#include <map>
using namespace std;

class RangeModule {
private:
    map<int,int> intervals; // start -> end

public:
    RangeModule() {}

    void addRange(int left, int right) {
        if (left >= right) return;

        auto it = intervals.lower_bound(left);

        // Merge with previous if overlapping
        if (it != intervals.begin()) {
            auto prev = it;
            prev--;
            if (prev->second >= left) {
                left = min(left, prev->first);
                right = max(right, prev->second);
                it = intervals.erase(prev);
            }
        }

        // Merge overlapping intervals
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);

        if (it == intervals.begin()) return false;

        it--;

        return it->second >= right;
    }

    void removeRange(int left, int right) {
        if (left >= right) return;

        auto it = intervals.lower_bound(left);

        if (it != intervals.begin()) {
            it--;
        }

        while (it != intervals.end()) {
            if (it->second <= left) {
                it++;
                continue;
            }

            if (it->first >= right) break;

            int start = it->first;
            int end = it->second;

            it = intervals.erase(it);

            if (start < left)
                intervals[start] = left;

            if (end > right)
                intervals[right] = end;
        }
    }
};