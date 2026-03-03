class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<pair<int,int>> starts; // (start, original_index)

        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());

        vector<int> result(n);

        for (int i = 0; i < n; i++) {

            int target = intervals[i][1];

            // Binary search
            int left = 0, right = n - 1;
            int ans = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (starts[mid].first >= target) {
                    ans = starts[mid].second;
                    right = mid - 1;   // search smaller valid
                } else {
                    left = mid + 1;
                }
            }

            result[i] = ans;
        }

        return result;
    }
};