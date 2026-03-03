class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1])
                left = mid + 1;     // go right
            else
                right = mid;        // go left
        }

        return left;   // or right
    }
};