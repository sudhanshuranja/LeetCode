var summaryRanges = function(nums) {
    const res = [];
    let i = 0;
    while (i < nums.length) {
        let start = i;
        while (i + 1 < nums.length && nums[i + 1] === nums[i] + 1) {
            i++;
        }
        if (start === i) {
            res.push(nums[start].toString());
        } else {
            res.push(nums[start] + "->" + nums[i]);
        }
        i++;
    }
    return res;
};