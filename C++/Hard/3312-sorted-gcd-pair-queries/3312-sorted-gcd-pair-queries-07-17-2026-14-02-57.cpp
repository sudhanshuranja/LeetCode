class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxV = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        // cnt[v] = number of elements equal to v
        vector<int> cnt(maxV + 1, 0);
        for (int x : nums) cnt[x]++;
        
        // multiplesCnt[g] = number of elements that are multiples of g
        vector<long long> multiplesCnt(maxV + 1, 0);
        for (int g = 1; g <= maxV; g++) {
            long long total = 0;
            for (int m = g; m <= maxV; m += g) {
                total += cnt[m];
            }
            multiplesCnt[g] = total;
        }
        
        // pairsMultiple[g] = number of pairs (i,j) where g divides both nums[i], nums[j]
        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(maxV + 1, 0);
        for (int g = maxV; g >= 1; g--) {
            long long M = multiplesCnt[g];
            long long pairsMultiple = M * (M - 1) / 2;
            long long sub = 0;
            for (int k = 2 * g; k <= maxV; k += g) {
                sub += exact[k];
            }
            exact[g] = pairsMultiple - sub;
        }
        
        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(maxV + 1, 0);
        for (int g = 1; g <= maxV; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            // find smallest g such that prefix[g] > q
            int lo = 1, hi = maxV, res = maxV;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] > q) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            answer.push_back(res);
        }
        
        return answer;
    }
};