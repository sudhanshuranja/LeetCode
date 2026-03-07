class Solution {
public:
    
    vector<int> parent;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa != pb){
            parent[pa] = pb;
        }
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        vector<bool> result;
        
        for(auto &req : requests){
            
            int u = req[0];
            int v = req[1];
            
            int pu = find(u);
            int pv = find(v);
            
            bool valid = true;
            
            for(auto &r : restrictions){
                
                int x = r[0];
                int y = r[1];
                
                int px = find(x);
                int py = find(y);
                
                if((pu == px && pv == py) || (pu == py && pv == px)){
                    valid = false;
                    break;
                }
            }
            
            if(valid){
                unite(pu, pv);
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        
        return result;
    }
};