class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int u, vector<int>& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, comp);

                int nodes = comp.size();
                int degreeSum = 0;

                for (int node : comp)
                    degreeSum += adj[node].size();

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};