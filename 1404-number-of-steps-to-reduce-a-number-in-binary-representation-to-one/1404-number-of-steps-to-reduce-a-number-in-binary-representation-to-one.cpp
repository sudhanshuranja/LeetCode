class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for(int i = s.size() - 1; i > 0; i--) {
            int bit = s[i] - '0';
            int current = bit + carry;
            
            if(current == 1) {
                steps += 2;   // add 1 + divide
                carry = 1;
            } else {
                steps += 1;   // divide only
            }
        }
        
        return steps + carry;
    }
};