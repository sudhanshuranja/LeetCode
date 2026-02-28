class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;

        for(char c : word) {
            if(isupper(c)) {
                capitalCount++;
            }
        }

        if(capitalCount == word.length()) return true;
        if(capitalCount == 0) return true;
        if(capitalCount == 1 && isupper(word[0])) return true;

        return false;
    }
};