class Solution {

    static final int DRAW = 0;
    static final int MOUSE = 1;
    static final int CAT = 2;

    public int catMouseGame(int[][] graph) {

        int n = graph.length;

        int[][][] color = new int[n][n][2];
        int[][][] degree = new int[n][n][2];

        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {

                degree[m][c][0] = graph[m].length;
                degree[m][c][1] = graph[c].length;

                for (int next : graph[c]) {
                    if (next == 0)
                        degree[m][c][1]--;
                }
            }
        }

        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int t = 0; t < 2; t++) {

                if (i > 0) {
                    color[0][i][t] = MOUSE;
                    q.offer(new int[]{0, i, t, MOUSE});

                    color[i][i][t] = CAT;
                    q.offer(new int[]{i, i, t, CAT});
                }
            }
        }

        while (!q.isEmpty()) {

            int[] cur = q.poll();

            int m = cur[0];
            int c = cur[1];
            int turn = cur[2];
            int result = cur[3];

            for (int[] prev : parents(graph, m, c, turn)) {

                int pm = prev[0];
                int pc = prev[1];
                int pt = prev[2];

                if (color[pm][pc][pt] != DRAW)
                    continue;

                if (pt == 0 && result == MOUSE ||
                    pt == 1 && result == CAT) {

                    color[pm][pc][pt] = result;
                    q.offer(new int[]{pm, pc, pt, result});

                } else {

                    degree[pm][pc][pt]--;

                    if (degree[pm][pc][pt] == 0) {

                        int lose = pt == 0 ? CAT : MOUSE;

                        color[pm][pc][pt] = lose;
                        q.offer(new int[]{pm, pc, pt, lose});
                    }
                }
            }
        }

        return color[1][2][0];
    }

    private List<int[]> parents(int[][] graph, int m, int c, int turn) {

        List<int[]> res = new ArrayList<>();

        if (turn == 1) {

            for (int pm : graph[m])
                res.add(new int[]{pm, c, 0});

        } else {

            for (int pc : graph[c]) {
                if (pc != 0)
                    res.add(new int[]{m, pc, 1});
            }
        }

        return res;
    }
}