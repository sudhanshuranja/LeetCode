class Solution {
public:
    int ans = 0;

    void dfs(int node, int time, int score,
             vector<int>& values,
             vector<vector<pair<int,int>>>& graph,
             vector<int>& visit,
             int maxTime) {

        if(node == 0)
            ans = max(ans, score);

        for(auto &edge : graph[node]) {
            int next = edge.first;
            int cost = edge.second;

            if(time + cost > maxTime)
                continue;

            bool firstVisit = visit[next] == 0;
            visit[next]++;

            dfs(next,
                time + cost,
                score + (firstVisit ? values[next] : 0),
                values,
                graph,
                visit,
                maxTime);

            visit[next]--;
        }
    }

    int maximalPathQuality(vector<int>& values,
                           vector<vector<int>>& edges,
                           int maxTime) {

        int n = values.size();
        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }

        vector<int> visit(n,0);
        visit[0] = 1;

        dfs(0, 0, values[0], values, graph, visit, maxTime);

        return ans;
    }
};