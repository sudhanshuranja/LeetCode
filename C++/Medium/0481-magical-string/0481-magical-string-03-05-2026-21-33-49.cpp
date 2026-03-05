class Solution {
public:
    int magicalString(int n) {
        
        if(n <= 3) return 1;
        
        vector<int> s(n + 2);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;
        
        int i = 2;
        int num = 1;
        int count = 1;
        int size = 3;
        
        while(size < n){
            
            for(int j = 0; j < s[i] && size < n; j++){
                s[size] = num;
                if(num == 1) count++;
                size++;
            }
            
            num = (num == 1) ? 2 : 1;
            i++;
        }
        
        return count;
    }
};