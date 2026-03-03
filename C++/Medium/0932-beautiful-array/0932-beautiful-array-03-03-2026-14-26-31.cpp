class Solution {
public:
    vector<int> beautifulArray(int n) {

        vector<int> res = {1};

        while (res.size() < n) {

            vector<int> temp;

            // Odd part
            for (int x : res) {
                if (2*x - 1 <= n)
                    temp.push_back(2*x - 1);
            }

            // Even part
            for (int x : res) {
                if (2*x <= n)
                    temp.push_back(2*x);
            }

            res = temp;
        }

        return res;
    }
};