class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + (x % 10);
            x /= 10;
        }

        // For even length: x == reversedHalf
        // For odd length:  x == reversedHalf/10 (middle digit removed)
        return (x == reversedHalf) || (x == reversedHalf / 10);
    }
};
