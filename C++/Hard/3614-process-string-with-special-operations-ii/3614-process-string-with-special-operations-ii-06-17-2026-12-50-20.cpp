class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);

        const long long LIM = (long long)1e15 + 1;

        // Forward: compute lengths
        for (int i = 0; i < n; i++) {
            long long cur = len[i];

            if ('a' <= s[i] && s[i] <= 'z') {
                len[i + 1] = min(LIM, cur + 1);
            } 
            else if (s[i] == '*') {
                len[i + 1] = max(0LL, cur - 1);
            } 
            else if (s[i] == '#') {
                len[i + 1] = min(LIM, cur * 2);
            } 
            else { // '%'
                len[i + 1] = cur;
            }
        }

        if (k >= len[n]) return '.';

        // Backward: trace index k
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (k == len[i + 1] - 1)
                    return ch;
            }
            else if (ch == '#') {
                if (len[i] > 0)
                    k %= len[i];
            }
            else if (ch == '%') {
                if (len[i] > 0)
                    k = len[i] - 1 - k;
            }
            // '*' needs no change
        }

        return '.';
    }
};