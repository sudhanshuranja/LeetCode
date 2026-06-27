class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1)) {
            int ones = cnt[1];
            ans = max(ans, (ones % 2 == 0) ? ones - 1 : ones);
        }

        for (auto &[start, freq] : cnt) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) break;

                if (cnt[cur] >= 2) {
                    len += 2;
                } else {
                    len += 1;
                    break;
                }

                if (cur > 1000000000LL / cur)
                    break;

                cur = cur * cur;
            }

            if (len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};