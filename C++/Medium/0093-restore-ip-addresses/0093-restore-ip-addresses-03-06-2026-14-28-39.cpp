class Solution {
public:
    vector<string> result;

    bool valid(string s){
        if(s.size() > 1 && s[0] == '0') return false;
        if(stoi(s) > 255) return false;
        return true;
    }

    void backtrack(string s, int start, int parts, string current){
        
        if(parts == 4 && start == s.size()){
            current.pop_back(); 
            result.push_back(current);
            return;
        }

        if(parts >= 4) return;

        for(int len = 1; len <= 3 && start + len <= s.size(); len++){
            
            string segment = s.substr(start, len);

            if(valid(segment)){
                backtrack(s, start + len, parts + 1, current + segment + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};