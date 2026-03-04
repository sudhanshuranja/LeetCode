class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int n = apples.size();
        int day = 0, eaten = 0;

        while(day < n || !pq.empty()) {

            if(day < n && apples[day] > 0)
                pq.push({day + days[day], apples[day]});

            while(!pq.empty() && pq.top().first <= day)
                pq.pop();

            if(!pq.empty()) {
                auto top = pq.top();
                pq.pop();

                eaten++;

                if(top.second > 1)
                    pq.push({top.first, top.second - 1});
            }

            day++;
        }

        return eaten;
    }
};