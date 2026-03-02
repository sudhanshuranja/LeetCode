class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rightmost(n);

        // Step 1: find rightmost 1 in each row
        for(int i=0;i<n;i++){
            int pos = -1;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    pos = j;
            }
            rightmost[i] = pos;
        }

        int swaps = 0;

        // Step 2: greedy row fixing
        for(int i=0;i<n;i++){

            int j = i;

            // find row that can satisfy condition
            while(j < n && rightmost[j] > i)
                j++;

            if(j == n)
                return -1;

            // bubble up
            while(j > i){
                swap(rightmost[j], rightmost[j-1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};