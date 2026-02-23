#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class StreamChecker {
private:
    TrieNode* root;
    string stream;
    int maxLen = 0;

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();

        for (string& word : words) {
            maxLen = max(maxLen, (int)word.size());
            insert(word);
        }
    }

    void insert(string& word) {
        TrieNode* node = root;

        // insert reversed
        for (int i = word.size() - 1; i >= 0; i--) {
            int index = word[i] - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool query(char letter) {
        stream.push_back(letter);

        TrieNode* node = root;

        // check only up to max word length
        for (int i = stream.size() - 1; 
             i >= 0 && stream.size() - i <= maxLen; 
             i--) {

            int index = stream[i] - 'a';
            if (!node->children[index])
                return false;

            node = node->children[index];

            if (node->isEnd)
                return true;
        }

        return false;
    }
};