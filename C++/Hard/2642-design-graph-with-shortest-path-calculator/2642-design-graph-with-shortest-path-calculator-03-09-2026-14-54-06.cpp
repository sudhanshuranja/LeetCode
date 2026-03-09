class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> graph;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);

        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0,node1});
        dist[node1] = 0;

        while(!pq.empty()) {

            auto [d,u] = pq.top();
            pq.pop();

            if(u == node2)
                return d;

            if(d > dist[u])
                continue;

            for(auto &[v,w] : graph[u]) {

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */