var calcEquation = function(equations, values, queries) {
    const graph = new Map();

    equations.forEach(([a, b], i) => {
        if (!graph.has(a)) graph.set(a, new Map());
        if (!graph.has(b)) graph.set(b, new Map());
        graph.get(a).set(b, values[i]);
        graph.get(b).set(a, 1 / values[i]);
    });

    const dfs = (src, dst, visited) => {
        if (!graph.has(src) || !graph.has(dst)) return -1.0;
        if (src === dst) return 1.0;
        visited.add(src);
        for (const [neighbor, val] of graph.get(src)) {
            if (!visited.has(neighbor)) {
                const result = dfs(neighbor, dst, visited);
                if (result !== -1.0) return result * val;
            }
        }
        return -1.0;
    };

    return queries.map(([a, b]) => dfs(a, b, new Set()));
};