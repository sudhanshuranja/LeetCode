#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct SegTree {
        int n;
        vector<int> mn, mx, lazy;

        SegTree(int n): n(n) {
            mn.assign(4*n, 0);
            mx.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }

        void push(int idx) {
            if(lazy[idx] == 0) return;
            int v = lazy[idx];
            for(int c : {idx*2, idx*2+1}) {
                mn[c] += v;
                mx[c] += v;
                lazy[c] += v;
            }
            lazy[idx] = 0;
        }

        void pull(int idx) {
            mn[idx] = min(mn[idx*2], mn[idx*2+1]);
            mx[idx] = max(mx[idx*2], mx[idx*2+1]);
        }

        void add(int idx, int l, int r, int ql, int qr, int val) {
            if(qr < l || r < ql) return;
            if(ql <= l && r <= qr) {
                mn[idx] += val;
                mx[idx] += val;
                lazy[idx] += val;
                return;
            }
            push(idx);
            int mid = (l+r)/2;
            add(idx*2, l, mid, ql, qr, val);
            add(idx*2+1, mid+1, r, ql, qr, val);
            pull(idx);
        }

        void add(int l, int r, int val) {
            if(l > r) return;
            add(1, 0, n-1, l, r, val);
        }

        // Find minimum index l where value == 0
        int firstZero(int idx, int l, int r) {
            if(mn[idx] > 0 || mx[idx] < 0) return -1;
            if(l == r) return l;
            push(idx);
            int mid = (l+r)/2;
            int left = firstZero(idx*2, l, mid);
            if(left != -1) return left;
            return firstZero(idx*2+1, mid+1, r);
        }

        int firstZero() {
            return firstZero(1, 0, n-1);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        const int MAXV = 100000;

        vector<vector<int>> pos(MAXV + 1);
        for(int i=0;i<n;i++) pos[nums[i]].push_back(i);

        vector<int> ptr(MAXV + 1, 0);

        auto sgn = [&](int x)->int {
            return (x & 1) ? 1 : -1;
        };

        SegTree st(n);

        // Initially for each l, balance(l, -1)=0
        // We sweep r from 0..n-1 and update all l <= firstOcc(nums[r]) with +/-1
        // So the segment tree stores balance(l, r) for all l.

        // For each value, first occurrence is pos[v][0]
        // When we see nums[r], if this is its k-th occurrence:
        // it contributes only for l in (prevOcc+1 .. currOcc]
        // We do range add over l.

        vector<int> last(MAXV+1, -1);

        int ans = 0;

        for(int r=0;r<n;r++) {
            int x = nums[r];
            int s = sgn(x);

            int prev = last[x];
            last[x] = r;

            // This number becomes "distinct" in subarray [l..r]
            // exactly when l > prev
            // So for l in [prev+1 .. r], we add s to balance(l,r)
            st.add(prev+1, r, s);

            // Now we need any l such that balance(l,r)=0
            // We want MIN l with 0 to maximize length (r-l+1)
            int l0 = st.firstZero();
            if(l0 != -1) ans = max(ans, r - l0 + 1);
        }

        return ans;
    }
};
