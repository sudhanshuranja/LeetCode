class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivotIndex = low + rand() % (high - low + 1);
        swap(nums[pivotIndex], nums[high]);

        int p = partition(nums, low, high);

        quickSort(nums, low, p - 1);
        quickSort(nums, p + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);
        return i;
    }
};