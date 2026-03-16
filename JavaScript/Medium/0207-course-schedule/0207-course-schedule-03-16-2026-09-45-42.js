/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {

    const graph = Array.from({length: numCourses}, () => []);
    const indegree = new Array(numCourses).fill(0);

    for (let [a, b] of prerequisites) {
        graph[b].push(a);
        indegree[a]++;
    }

    const queue = [];

    for (let i = 0; i < numCourses; i++) {
        if (indegree[i] === 0) queue.push(i);
    }

    let completed = 0;

    while (queue.length) {
        let course = queue.shift();
        completed++;

        for (let next of graph[course]) {
            indegree[next]--;
            if (indegree[next] === 0) queue.push(next);
        }
    }

    return completed === numCourses;
};