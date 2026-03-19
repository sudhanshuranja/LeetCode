class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Step 1: Check compatibility
        if (str1 + str2 != str2 + str1) return "";
        
        // Step 2: Find GCD of lengths
        int gcdLen = gcd(str1.size(), str2.size());
        
        // Step 3: Return prefix of that length
        return str1.substr(0, gcdLen);
    }
};