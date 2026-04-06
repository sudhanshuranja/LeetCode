class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        // Step 1: Length check
        if (word1.length() != word2.length()) return false;

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        // Step 2: Count frequencies
        for (char c : word1.toCharArray()) {
            freq1[c - 'a']++;
        }
        for (char c : word2.toCharArray()) {
            freq2[c - 'a']++;
        }

        // Step 3: Check same character set
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || 
                (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        // Step 4: Sort and compare frequencies
        Arrays.sort(freq1);
        Arrays.sort(freq2);

        return Arrays.equals(freq1, freq2);
    }
}