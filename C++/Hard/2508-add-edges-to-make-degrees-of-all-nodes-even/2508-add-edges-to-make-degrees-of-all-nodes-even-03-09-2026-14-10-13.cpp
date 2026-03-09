class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1,0);
        unordered_set<long long> st;

        for(auto &e:edges){
            int a=e[0], b=e[1];
            degree[a]++;
            degree[b]++;
            st.insert((long long)a<<32 | b);
            st.insert((long long)b<<32 | a);
        }

        vector<int> odd;
        for(int i=1;i<=n;i++){
            if(degree[i]%2) odd.push_back(i);
        }

        auto hasEdge=[&](int a,int b){
            return st.count((long long)a<<32 | b);
        };

        if(odd.size()==0) return true;

        if(odd.size()==2){
            int a=odd[0], b=odd[1];

            if(!hasEdge(a,b)) return true;

            for(int i=1;i<=n;i++){
                if(i!=a && i!=b && !hasEdge(a,i) && !hasEdge(b,i))
                    return true;
            }
            return false;
        }

        if(odd.size()==4){
            int a=odd[0], b=odd[1], c=odd[2], d=odd[3];

            if(!hasEdge(a,b) && !hasEdge(c,d)) return true;
            if(!hasEdge(a,c) && !hasEdge(b,d)) return true;
            if(!hasEdge(a,d) && !hasEdge(b,c)) return true;

            return false;
        }

        return false;
    }
};