class Solution {

    int[] tree;
    int n;

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        n = baskets.length;
        tree = new int[4 * n];

        build(baskets, 1, 0, n - 1);

        int unplaced = 0;

        for (int f : fruits) {
            int idx = query(1, 0, n - 1, f);

            if (idx == -1) {
                unplaced++;
            } else {
                update(1, 0, n - 1, idx);
            }
        }

        return unplaced;
    }

    private void build(int[] arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(arr, node * 2, l, mid);
        build(arr, node * 2 + 1, mid + 1, r);

        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }

    private int query(int node, int l, int r, int val) {
        if (tree[node] < val) return -1;

        if (l == r) return l;

        int mid = (l + r) / 2;

        if (tree[node * 2] >= val)
            return query(node * 2, l, mid, val);
        else
            return query(node * 2 + 1, mid + 1, r, val);
    }

    private void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node] = 0;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx);
        else
            update(node * 2 + 1, mid + 1, r, idx);

        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }
}