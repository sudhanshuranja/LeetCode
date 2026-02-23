class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        // If string smaller than k → impossible
        if (k > n) return false;
        
        // Early pruning:
        // Total substrings of size k = n - k + 1
        // Required unique binary codes = 2^k
        if (n - k + 1 < (1 << k)) return false;
        
        unordered_set<int> seen;
        
        int hash = 0;
        int mask = (1 << k) - 1;   // Keep only last k bits
        
        for (int i = 0; i < n; i++) {
            // Left shift, add current bit, remove overflow bits
            hash = ((hash << 1) & mask) | (s[i] - '0');
            
            // Start recording once window size reaches k
            if (i >= k - 1) {
                seen.insert(hash);
                
                if (seen.size() == (1 << k))
                    return true;
            }
        }
        
        return false;
    }
};