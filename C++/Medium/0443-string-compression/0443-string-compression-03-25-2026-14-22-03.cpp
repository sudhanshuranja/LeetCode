class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0, write = 0;

        while (read < n) {
            char current = chars[read];
            int count = 0;

            // Count occurrences
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            // Write character
            chars[write++] = current;

            // Write count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};