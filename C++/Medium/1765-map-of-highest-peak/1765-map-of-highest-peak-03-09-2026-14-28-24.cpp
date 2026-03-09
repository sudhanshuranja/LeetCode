class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){

            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dir){

                int nx = x + d[0];
                int ny = y + d[1];

                if(nx>=0 && ny>=0 && nx<m && ny<n && height[nx][ny]==-1){

                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        return height;
    }
};