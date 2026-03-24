class ArrayWrapper {
    constructor(nums) {
        this.nums = nums;
    }

    // Used when + operator is applied
    valueOf() {
        return this.nums.reduce((sum, num) => sum + num, 0);
    }

    // Used when String() is called
    toString() {
        return `[${this.nums.join(',')}]`;
    }
}