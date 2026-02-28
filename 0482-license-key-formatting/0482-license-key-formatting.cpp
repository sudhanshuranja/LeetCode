class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned = "";

        // Step 1: Remove dashes and convert to uppercase
        for(char c : s) {
            if(c != '-') {
                cleaned += toupper(c);
            }
        }

        string result = "";
        int count = 0;

        // Step 2: Traverse from end
        for(int i = cleaned.length() - 1; i >= 0; i--) {
            result += cleaned[i];
            count++;

            if(count == k && i != 0) {
                result += '-';
                count = 0;
            }
        }

        // Step 3: Reverse final answer
        reverse(result.begin(), result.end());

        return result;
    }
};