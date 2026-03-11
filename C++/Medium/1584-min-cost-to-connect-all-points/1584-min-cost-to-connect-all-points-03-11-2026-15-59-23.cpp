class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        int result = 0;
        minDist[0] = 0;

        for(int i = 0; i < n; i++) {
            
            int u = -1;

            for(int j = 0; j < n; j++) {
                if(!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                    u = j;
            }

            visited[u] = true;
            result += minDist[u];

            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return result;
    }
};