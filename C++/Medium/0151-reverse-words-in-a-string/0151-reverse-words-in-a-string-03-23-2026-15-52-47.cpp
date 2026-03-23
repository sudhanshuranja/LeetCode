class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        
        // Extract words (auto removes extra spaces)
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse words
        reverse(words.begin(), words.end());
        
        // Join with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};