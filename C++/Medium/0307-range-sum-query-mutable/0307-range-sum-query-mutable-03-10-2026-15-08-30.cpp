class NumArray {
private:
    vector<int> tree;
    vector<int> nums;
    int n;

    void updateTree(int index, int diff) {
        index++;
        while (index <= n) {
            tree[index] += diff;
            index += index & (-index);
        }
    }

    int query(int index) {
        index++;
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            updateTree(i, nums[i]);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateTree(index, diff);
    }

    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */