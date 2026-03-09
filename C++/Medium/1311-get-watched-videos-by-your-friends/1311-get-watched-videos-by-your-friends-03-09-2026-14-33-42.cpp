class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id, int level) {

        int n = friends.size();

        vector<int> vis(n,0);
        queue<int> q;

        q.push(id);
        vis[id] = 1;

        int currLevel = 0;

        while(!q.empty() && currLevel < level) {

            int sz = q.size();

            for(int i=0;i<sz;i++) {
                int node = q.front();
                q.pop();

                for(int nei : friends[node]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            currLevel++;
        }

        unordered_map<string,int> freq;

        while(!q.empty()) {

            int person = q.front();
            q.pop();

            for(auto &video : watchedVideos[person]) {
                freq[video]++;
            }
        }

        vector<pair<string,int>> arr(freq.begin(), freq.end());

        sort(arr.begin(), arr.end(),
        [](auto &a, auto &b) {
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> result;

        for(auto &p : arr)
            result.push_back(p.first);

        return result;
    }
};