class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;

        char[] word = new char[len];
        boolean[] locked = new boolean[len];

        for (int i = 0; i < len; i++) word[i] = '?';

        // Step 1: Apply 'T' and lock positions
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2.charAt(j)) {
                        word[i + j] = str2.charAt(j);
                        locked[i + j] = true; // 🔒 lock
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 3: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'F') {
                boolean match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2.charAt(j)) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    boolean changed = false;

                    // Try to modify non-locked position
                    for (int j = m - 1; j >= 0; j--) {
                        if (!locked[i + j] && word[i + j] != 'z') {
                            word[i + j]++;
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return ""; // ❌ cannot fix
                }
            }
        }

        return new String(word);
    }
}