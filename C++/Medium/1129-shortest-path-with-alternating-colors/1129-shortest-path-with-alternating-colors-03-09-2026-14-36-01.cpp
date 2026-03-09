class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<int>> red(n), blue(n);

        for(auto &e : redEdges)
            red[e[0]].push_back(e[1]);

        for(auto &e : blueEdges)
            blue[e[0]].push_back(e[1]);

        vector<vector<int>> vis(n, vector<int>(2,0));

        vector<int> ans(n, -1);

        queue<pair<int,int>> q;

        q.push({0,0}); // last edge red
        q.push({0,1}); // last edge blue

        vis[0][0] = vis[0][1] = 1;

        int dist = 0;

        while(!q.empty()) {

            int sz = q.size();

            for(int i=0;i<sz;i++) {

                auto [node,color] = q.front();
                q.pop();

                if(ans[node] == -1)
                    ans[node] = dist;

                if(color == 0) { 
                    for(int next : blue[node]) {
                        if(!vis[next][1]) {
                            vis[next][1] = 1;
                            q.push({next,1});
                        }
                    }
                }
                else {
                    for(int next : red[node]) {
                        if(!vis[next][0]) {
                            vis[next][0] = 1;
                            q.push({next,0});
                        }
                    }
                }
            }

            dist++;
        }

        return ans;
    }
};