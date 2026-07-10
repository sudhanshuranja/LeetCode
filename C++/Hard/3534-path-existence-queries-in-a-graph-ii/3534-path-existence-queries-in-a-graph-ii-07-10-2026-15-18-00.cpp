class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        ord.reserve(n);
        for (int i = 0; i < n; i++) ord.push_back({nums[i], i});
        sort(ord.begin(), ord.end());

        vector<int> pos(n), val(n);
        for (int i = 0; i < n; i++) {
            val[i] = ord[i].first;
            pos[ord[i].second] = i;
        }

        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff) cid++;
            comp[i] = cid;
        }

        vector<int> right(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && val[j + 1] - val[i] <= maxDiff) j++;
            right[i] = j;
        }

        vector<int> left(n);
        int l = 0;
        for (int i = 0; i < n; i++) {
            while (val[i] - val[l] > maxDiff) l++;
            left[i] = l;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> upR(LOG, vector<int>(n));
        vector<vector<int>> upL(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            upR[0][i] = right[i];
            upL[0][i] = left[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u < v) {
                int cur = u;
                int steps = 0;
                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = upR[k][cur];
                    if (nxt < v && nxt > cur) {
                        cur = nxt;
                        steps += (1 << k);
                    }
                }
                ans.push_back(steps + 1);
            } else {
                int cur = u;
                int steps = 0;
                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = upL[k][cur];
                    if (nxt > v && nxt < cur) {
                        cur = nxt;
                        steps += (1 << k);
                    }
                }
                ans.push_back(steps + 1);
            }
        }

        return ans;
    }
};