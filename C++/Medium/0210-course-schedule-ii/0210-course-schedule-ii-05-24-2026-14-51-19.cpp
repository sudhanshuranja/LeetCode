class Solution {
public:
    
    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        // Build graph
        vector<vector<int>> graph(numCourses);

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        // Indegree array
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            for (auto neigh : graph[i]) {
                indegree[neigh]++;
            }
        }

        // Queue for nodes having indegree 0
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0)
                q.push(i);
        }

        // Stores topological order
        vector<int> order;

        // BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            order.push_back(node);

            for (auto neigh : graph[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // If cycle exists
        if (order.size() != numCourses)
            return {};

        return order;
    }
};