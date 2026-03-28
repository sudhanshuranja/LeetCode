class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;

        // Step 1: Check diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        // Step 2: Union-Find
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        // Find
        java.util.function.IntUnaryOperator find = new java.util.function.IntUnaryOperator() {
            public int applyAsInt(int x) {
                if (parent[x] != x) parent[x] = applyAsInt(parent[x]);
                return parent[x];
            }
        };

        // Union
        java.util.function.BiConsumer<Integer, Integer> union = (a, b) -> {
            int pa = find.applyAsInt(a);
            int pb = find.applyAsInt(b);
            if (pa != pb) parent[pa] = pb;
        };

        // Merge groups
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = lcp[i][j];
                for (int k = 0; k < len; k++) {
                    if (i + k < n && j + k < n) {
                        union.accept(i + k, j + k);
                    }
                }
            }
        }

        // Step 3: Assign characters
        char[] res = new char[n];
        java.util.Map<Integer, Character> map = new java.util.HashMap<>();

        char ch = 'a';
        for (int i = 0; i < n; i++) {
            int root = find.applyAsInt(i);
            if (!map.containsKey(root)) {
                if (ch > 'z') return "";
                map.put(root, ch++);
            }
            res[i] = map.get(root);
        }

        String word = new String(res);

        // Step 4: Recompute LCP
        int[][] check = new int[n][n];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word.charAt(i) == word.charAt(j)) {
                    if (i + 1 < n && j + 1 < n)
                        check[i][j] = 1 + check[i + 1][j + 1];
                    else
                        check[i][j] = 1;
                }
            }
        }

        // Compare
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }
}