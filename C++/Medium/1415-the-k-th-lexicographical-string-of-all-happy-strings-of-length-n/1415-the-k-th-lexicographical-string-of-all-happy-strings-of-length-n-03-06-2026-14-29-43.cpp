class Solution {
public:
    vector<string> result;

    void backtrack(string curr, int n){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                backtrack(curr + c, n);
            }
        }
    }

    string getHappyString(int n, int k) {
        backtrack("", n);

        if(result.size() < k)
            return "";

        return result[k-1];
    }
};