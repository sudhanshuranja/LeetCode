import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        
        // Step 1: Count frequencies
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        // Step 2: Check uniqueness
        Set<Integer> set = new HashSet<>();
        for (int freq : map.values()) {
            if (set.contains(freq)) {
                return false;
            }
            set.add(freq);
        }
        
        return true;
    }
}