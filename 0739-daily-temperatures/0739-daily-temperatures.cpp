class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> answer(n, 0);
        stack<int> st; // stores indices
        
        for(int i = n-1; i >= 0; i--) {
            
            while(!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                answer[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return answer;
    }
};