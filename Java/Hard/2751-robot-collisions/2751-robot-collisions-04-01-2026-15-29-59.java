import java.util.*;

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;

        // Step 1: Create robot array
        int[][] robots = new int[n][4]; // pos, health, dir, index
        for (int i = 0; i < n; i++) {
            robots[i][0] = positions[i];
            robots[i][1] = healths[i];
            robots[i][2] = directions.charAt(i); // 'L' or 'R'
            robots[i][3] = i;
        }

        // Step 2: Sort by position
        Arrays.sort(robots, (a, b) -> a[0] - b[0]);

        Stack<Integer> stack = new Stack<>();

        // Step 3: Process robots
        for (int i = 0; i < n; i++) {
            if (robots[i][2] == 'R') {
                stack.push(i);
            } else {
                // current is 'L'
                while (!stack.isEmpty() && robots[i][1] > 0) {
                    int top = stack.peek();

                    if (robots[top][1] < robots[i][1]) {
                        // R dies
                        stack.pop();
                        robots[i][1] -= 1;
                        robots[top][1] = 0;
                    } 
                    else if (robots[top][1] > robots[i][1]) {
                        // L dies
                        robots[top][1] -= 1;
                        robots[i][1] = 0;
                        break;
                    } 
                    else {
                        // both die
                        stack.pop();
                        robots[top][1] = 0;
                        robots[i][1] = 0;
                        break;
                    }
                }
            }
        }

        // Step 4: Collect survivors
        int[] result = new int[n];
        for (int[] robot : robots) {
            if (robot[1] > 0) {
                result[robot[3]] = robot[1];
            }
        }

        // Step 5: Return in original order
        List<Integer> ans = new ArrayList<>();
        for (int val : result) {
            if (val > 0) ans.add(val);
        }

        return ans;
    }
}