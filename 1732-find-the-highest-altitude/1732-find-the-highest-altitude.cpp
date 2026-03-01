class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxAlt = 0;

        for(int g : gain) {
            alt += g;
            maxAlt = max(maxAlt, alt);
        }

        return maxAlt;
    }
};