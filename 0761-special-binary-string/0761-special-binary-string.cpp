#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> result;
        int count = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                count++;
            else
                count--;
            
            // When balanced substring found
            if (count == 0) {
                // Recursively process inner part
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                
                // Wrap it again with 1 and 0
                result.push_back("1" + inner + "0");
                
                start = i + 1;
            }
        }
        
        // Sort in descending lexicographical order
        sort(result.begin(), result.end(), greater<string>());
        
        // Combine all parts
        string ans = "";
        for (string &str : result)
            ans += str;
        
        return ans;
    }
};