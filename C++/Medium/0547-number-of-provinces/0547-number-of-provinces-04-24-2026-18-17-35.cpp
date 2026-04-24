class Solution {
public:
    void dfs(int node, vector<int>ads[],  vector<int> &vis)
    {
        vis[node] = 1;
        for(auto it:ads[node])
        {
            if(vis[it]!=1)
            {
                dfs(it, ads, vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int v = isConnected.size();
        vector<int>ads[v];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    ads[i].push_back(j);
                    ads[j].push_back(i);
                }
            }
        }
        vector<int>vis(v,0);
        int cnt=0;
        for(int i=0;i<v;i++)
        {
            if(vis[i]!=1)
            {
                dfs(i, ads, vis);
                cnt++;
            }
        }
        return cnt;
    }
//please upvote...
};