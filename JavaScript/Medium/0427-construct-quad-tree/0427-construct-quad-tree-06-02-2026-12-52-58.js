/**
 * // Definition for a QuadTree node.
 * function _Node(val,isLeaf,topLeft,topRight,bottomLeft,bottomRight) {
 *    this.val = val;
 *    this.isLeaf = isLeaf;
 *    this.topLeft = topLeft;
 *    this.topRight = topRight;
 *    this.bottomLeft = bottomLeft;
 *    this.bottomRight = bottomRight;
 * };
 */

/**
 * @param {number[][]} grid
 * @return {_Node}
 */
var construct = function(grid) {
    const build = (x, y, size) => {
        if (size === 1) {
            return new Node(grid[x][y] === 1, true);
        }

        const half = size >> 1;
        const topLeft = build(x, y, half);
        const topRight = build(x, y + half, half);
        const bottomLeft = build(x + half, y, half);
        const bottomRight = build(x + half, y + half, half);

        if (
            topLeft.isLeaf &&
            topRight.isLeaf &&
            bottomLeft.isLeaf &&
            bottomRight.isLeaf &&
            topLeft.val === topRight.val &&
            topLeft.val === bottomLeft.val &&
            topLeft.val === bottomRight.val
        ) {
            return new Node(topLeft.val, true);
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    };

    return build(0, 0, grid.length);
};