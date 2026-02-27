class Solution {
public:
    int minOperations(string s, int k) {

        int n = s.size();
        int start = 0;

        for(char c : s)
            if(c == '0')
                start++;

        if(start == 0) return 0;

        vector<int> dist(n+1, -1);
        dist[start] = 0;

        set<int> even, odd;
        for(int i=0;i<=n;i++){
            if(i%2==0) even.insert(i);
            else odd.insert(i);
        }

        queue<int> q;
        q.push(start);

        if(start%2==0) even.erase(start);
        else odd.erase(start);

        while(!q.empty()){
            int z = q.front(); q.pop();
            int steps = dist[z];

            int low_i = max(0, k - (n - z));
            int high_i = min(k, z);

            int L = z + k - 2*high_i;
            int R = z + k - 2*low_i;

            if(L < 0) L = 0;
            if(R > n) R = n;

            int parity = (z + k) % 2;

            auto &target = (parity == 0 ? even : odd);

            auto it = target.lower_bound(L);
            vector<int> remove;

            while(it != target.end() && *it <= R){
                int nxt = *it;
                dist[nxt] = steps + 1;
                q.push(nxt);
                remove.push_back(nxt);
                ++it;
            }

            for(int v : remove)
                target.erase(v);
        }

        return dist[0];
    }
};