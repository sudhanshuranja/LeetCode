class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, k = 0, ans = INT_MAX;
        int r = *max_element(piles.begin(), piles.end());
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            k = mid;
            long long cnt = 0;
            
            for (int a : piles) {
                if (k >= a)
                    cnt++;
                if (k < a) {
                    if (a % k != 0)
                        cnt = cnt + 1 + (a / k);
                    else
                        cnt += (a / k);
                }
            }
            
            if (cnt > h) {
                l = mid + 1;
            }
            if (cnt <= h) {
                ans = min(ans, k);
                r = mid - 1;
            }
        }
        
        return ans;
    }
};