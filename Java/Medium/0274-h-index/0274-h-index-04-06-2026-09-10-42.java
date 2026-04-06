import java.util.*;

class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations); // ascending
        
        int n = citations.length;
        int h = 0;
        
        for (int i = 0; i < n; i++) {
            int papers = n - i;
            
            if (citations[i] >= papers) {
                return papers;
            }
        }
        
        return 0;
    }
}