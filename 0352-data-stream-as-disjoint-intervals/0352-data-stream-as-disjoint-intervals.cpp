#include <map>
#include <vector>
using namespace std;

class SummaryRanges {
private:
    map<int, int> intervals; // start -> end

public:
    SummaryRanges() {}

    void addNum(int value) {
        if (intervals.empty()) {
            intervals[value] = value;
            return;
        }

        auto it = intervals.upper_bound(value);

        int start = value, end = value;

        // Check left interval
        if (it != intervals.begin()) {
            auto prev = it;
            prev--;

            if (prev->second >= value)
                return; // already covered

            if (prev->second + 1 == value) {
                start = prev->first;
                intervals.erase(prev);
            }
        }

        // Check right interval
        if (it != intervals.end() && it->first - 1 == value) {
            end = it->second;
            intervals.erase(it);
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto& [start, end] : intervals) {
            result.push_back({start, end});
        }
        return result;
    }
};