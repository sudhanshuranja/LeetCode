class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (vowels.count(s[left]) && vowels.count(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (!vowels.count(s[left])) {
                left++;
            }
            else {
                right--;
            }
        }

        return s;
    }
};