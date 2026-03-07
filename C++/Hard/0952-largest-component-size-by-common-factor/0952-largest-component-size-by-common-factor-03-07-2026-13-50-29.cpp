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
    
    int largestComponentSize(vector<int>& nums) {
        
        int maxNum = *max_element(nums.begin(), nums.end());
        parent.resize(maxNum + 1);
        
        for(int i = 0; i <= maxNum; i++)
            parent[i] = i;
        
        for(int num : nums){
            for(int f = 2; f * f <= num; f++){
                if(num % f == 0){
                    unite(num, f);
                    unite(num, num / f);
                }
            }
        }
        
        unordered_map<int,int> count;
        int ans = 0;
        
        for(int num : nums){
            int root = find(num);
            count[root]++;
            ans = max(ans, count[root]);
        }
        
        return ans;
    }
};