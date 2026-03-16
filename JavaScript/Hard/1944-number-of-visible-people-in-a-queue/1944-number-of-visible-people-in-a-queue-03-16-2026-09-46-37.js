/**
 * @param {number[]} heights
 * @return {number[]}
 */
var canSeePersonsCount = function(heights) {
    const n = heights.length;
    const res = new Array(n).fill(0);
    const stack = [];

    for (let i = n - 1; i >= 0; i--) {
        let count = 0;

        while (stack.length && heights[i] > stack[stack.length - 1]) {
            stack.pop();
            count++;
        }

        if (stack.length) count++;

        res[i] = count;
        stack.push(heights[i]);
    }

    return res;
};