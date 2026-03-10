#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q_len = queries.size();
        vector<int> ans(q_len, -1);
        
        // deferred[i] will store a list of {required_height, query_index}
        // for queries where the rightmost starting building is i
        vector<vector<pair<int, int>>> deferred(n);
        
        // 1. Process queries and handle immediate answers
        for (int i = 0; i < q_len; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            
            // Ensure u is the smaller index
            if (u > v) {
                swap(u, v);
            }
            
            if (u == v) {
                ans[i] = v;
            } else if (heights[u] < heights[v]) {
                ans[i] = v;
            } else {
                // Need a building strictly taller than heights[u] at some index > v
                deferred[v].push_back({heights[u], i});
            }
        }
        
        // 2. Min-heap to store active deferred queries
        // pair<int, int> represents {required_height, query_index}
        // Using greater<> turns the default Max-Heap into a Min-Heap based on the first element (required_height)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 3. Iterate over each building to find the answers
        for (int i = 0; i < n; ++i) {
            // If the current building is taller than the required height of the query
            // at the top of the heap, we found the leftmost building for that query.
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            
            // Add deferred queries ending at building i into the heap
            for (const auto& q : deferred[i]) {
                pq.push(q);
            }
        }
        
        return ans;
    }
};