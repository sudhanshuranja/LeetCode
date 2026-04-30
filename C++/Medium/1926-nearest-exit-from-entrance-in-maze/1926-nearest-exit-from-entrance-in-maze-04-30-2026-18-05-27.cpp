class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int ans = -1;
        vector<int> row = {0,0,-1,1};
        vector<int> col = {1,-1,0,0};
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==entrance[0]&& j==entrance[1])
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else if(maze[i][j]=='+')
                {
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty() && flag==true)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r = x + row[i];
                int c = y + col[i];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0)
                {
                    if(r==0||r==n-1||c==0||c==m-1) 
                    {
                        ans = d+1;
                        flag=!flag;
                        break;
                    }
                    q.push({{r,c},d+1});
                    vis[r][c] = 1;
                }
            }
        }
        return ans;
    }
//please upvote...
};