/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function(arr, n) {
    let result = [];

    function dfs(curr, depth) {
        for (let el of curr) {
            if (Array.isArray(el) && depth < n) {
                dfs(el, depth + 1);
            } else {
                result.push(el);
            }
        }
    }

    dfs(arr, 0);
    return result;
};