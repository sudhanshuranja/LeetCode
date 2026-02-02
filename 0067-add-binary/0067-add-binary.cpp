class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;

            // same logic as your code
            int sum = bitA ^ bitB ^ carry;          // XOR
            carry = (bitA & bitB) | (carry & (bitA ^ bitB)); // AND + shift idea

            result = char(sum + '0') + result;
        }

        return result;
    }
};
