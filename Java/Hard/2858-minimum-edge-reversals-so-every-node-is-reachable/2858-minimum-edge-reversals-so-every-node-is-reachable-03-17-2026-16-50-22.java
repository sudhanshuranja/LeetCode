import java.util.*;

class Solution {

    List<int[]>[] graph;
    int[] ans;

    public int[] minEdgeReversals(int n, int[][] edges) {

        graph = new ArrayList[n];
        ans = new int[n];

        for(int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        for(int[] e : edges) {

            int u = e[0], v = e[1];

            graph[u].add(new int[]{v,0});
            graph[v].add(new int[]{u,1});
        }

        dfs1(0,-1);
        dfs2(0,-1);

        return ans;
    }

    int dfs1(int node, int parent) {

        int count = 0;

        for(int[] nei : graph[node]) {

            int next = nei[0];
            int cost = nei[1];

            if(next == parent) continue;

            count += cost + dfs1(next,node);
        }

        return ans[0] = count;
    }

    void dfs2(int node, int parent) {

        for(int[] nei : graph[node]) {

            int next = nei[0];
            int cost = nei[1];

            if(next == parent) continue;

            ans[next] = ans[node] + (cost == 0 ? 1 : -1);

            dfs2(next,node);
        }
    }
}