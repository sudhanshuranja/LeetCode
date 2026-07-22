#include <bits/stdc++.h>
using namespace std;

struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        int LOG = n > 0 ? (int)floor(log2(n)) + 1 : 1;
        st.assign(LOG + 1, vector<int>(n, 0));
        if (n > 0) st[0] = nums;
        for (int i = 1; i <= LOG; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    // max(nums[l..r]) inclusive
    int query(int l, int r) const {
        int len = r - l + 1;
        int i = (int)floor(log2(len));
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    zeroGroups.back().length++;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        int ans_n = queries.size();
        vector<int> ans(ans_n);

        if (zeroGroups.empty()) {
            fill(ans.begin(), ans.end(), ones);
            return ans;
        }

        // merge lengths of adjacent zero groups: mergeLen[i] = zeroGroups[i].length + zeroGroups[i+1].length
        vector<int> mergeLen;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); i++)
            mergeLen.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);

        SparseTable st(mergeLen);

        for (int qi = 0; qi < ans_n; qi++) {
            int l = queries[qi][0], r = queries[qi][1];

            int gl = zeroGroupIndex[l]; // zero-group index containing l, or -1 if s[l]=='1'
            int gr = zeroGroupIndex[r]; // zero-group index containing r, or -1 if s[r]=='1'

            // truncated length of the (possibly partial) zero-group at l, counted from l to its end
            int left = (gl == -1) ? -1 : (zeroGroups[gl].length - (l - zeroGroups[gl].start));
            // truncated length of the (possibly partial) zero-group at r, counted from its start to r
            int right = (gr == -1) ? -1 : (r - zeroGroups[gr].start + 1);

            int startAdj = gl + 1;
            int endAdj = (s[r] == '1' ? gr : gr - 1) - 1;

            int activeSections = ones;

            // Case 1: l and r fall in the SAME zero group (whole range is inside one zero block)
            if (s[l] == '0' && s[r] == '0' && gl + 1 == gr) {
                // Note: gl+1==gr means l's group and r's group are adjacent groups,
                // NOT the same group. If truly the same group (gl==gr) it's handled elsewhere.
                activeSections = max(activeSections, ones + left + right);
            } else if (startAdj <= endAdj) {
                activeSections = max(activeSections, ones + st.query(startAdj, endAdj));
            }

            // Case: left partial zero group can merge with the immediately-following full zero group
            int rGroupBound = (s[r] == '1' ? gr : gr - 1);
            if (s[l] == '0' && gl + 1 <= rGroupBound) {
                activeSections = max(activeSections, ones + left + zeroGroups[gl + 1].length);
            }

            // Case: right partial zero group can merge with the immediately-preceding full zero group
            if (s[r] == '0' && gl < gr - 1) {
                activeSections = max(activeSections, ones + right + zeroGroups[gr - 1].length);
            }

            ans[qi] = activeSections;
        }

        return ans;
    }
};