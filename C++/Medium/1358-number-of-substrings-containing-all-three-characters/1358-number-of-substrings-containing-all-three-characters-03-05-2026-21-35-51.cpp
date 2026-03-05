class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int lastA = -1, lastB = -1, lastC = -1;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == 'a') lastA = i;
            if(s[i] == 'b') lastB = i;
            if(s[i] == 'c') lastC = i;
            
            int minPos = min({lastA, lastB, lastC});
            
            result += (minPos + 1);
        }
        
        return result;
    }
};