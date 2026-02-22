class Solution {
public:
    int binaryGap(int n) {
        int lastPosition = -1;
        int maxDistance = 0;
        int position = 0;

        while (n > 0) {
            if (n & 1) {   // If current bit is 1
                if (lastPosition != -1) {
                    maxDistance = max(maxDistance, position - lastPosition);
                }
                lastPosition = position;
            }
            n = n >> 1;   // Right shift
            position++;
        }

        return maxDistance;
    }
};