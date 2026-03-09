class Solution {
public:

    vector<long long> dijkstra(int n,
        vector<vector<pair<int,int>>>& graph,
        int src)
    {
        const long long INF = LLONG_MAX;
        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){

            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w] : graph[u]){

                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(
        int n,
        vector<vector<int>>& edges,
        int src1,
        int src2,
        int dest)
    {

        vector<vector<pair<int,int>>> graph(n);
        vector<vector<pair<int,int>>> rev(n);

        for(auto &e : edges){
            graph[e[0]].push_back({e[1],e[2]});
            rev[e[1]].push_back({e[0],e[2]});
        }

        auto d1 = dijkstra(n, graph, src1);
        auto d2 = dijkstra(n, graph, src2);
        auto d3 = dijkstra(n, rev, dest);

        long long ans = LLONG_MAX;

        for(int i=0;i<n;i++){

            if(d1[i]==LLONG_MAX ||
               d2[i]==LLONG_MAX ||
               d3[i]==LLONG_MAX)
               continue;

            ans = min(ans, d1[i]+d2[i]+d3[i]);
        }

        return ans==LLONG_MAX ? -1 : ans;
    }
};