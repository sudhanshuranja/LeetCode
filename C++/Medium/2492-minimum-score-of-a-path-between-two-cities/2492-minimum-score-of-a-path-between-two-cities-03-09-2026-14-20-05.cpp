class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> graph(n+1);

        for(auto &r : roads) {
            int u = r[0], v = r[1], d = r[2];
            graph[u].push_back({v,d});
            graph[v].push_back({u,d});
        }

        vector<int> vis(n+1,0);
        int ans = INT_MAX;

        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;

            for(auto &edge : graph[node]) {
                int next = edge.first;
                int dist = edge.second;

                ans = min(ans, dist);

                if(!vis[next])
                    dfs(next);
            }
        };

        dfs(1);

        return ans;
    }
};