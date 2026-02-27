class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        long long sum = 0;
        priority_queue<long long> pq;

        for(int x : target){
            sum += x;
            pq.push(x);
        }

        while(true){

            long long maxVal = pq.top(); pq.pop();
            long long rest = sum - maxVal;

            if(maxVal == 1 || rest == 1)
                return true;

            if(rest == 0 || maxVal < rest)
                return false;

            long long newVal = maxVal % rest;

            if(newVal == 0)
                return false;

            pq.push(newVal);
            sum = rest + newVal;
        }
    }
};