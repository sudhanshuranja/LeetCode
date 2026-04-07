class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalTank = 0;
        int currTank = 0;
        int start = 0;

        for (int i = 0; i < gas.length; i++) {
            int gain = gas[i] - cost[i];

            totalTank += gain;
            currTank += gain;

            // If current tank becomes negative
            if (currTank < 0) {
                start = i + 1;   // shift starting point
                currTank = 0;    // reset tank
            }
        }

        return totalTank >= 0 ? start : -1;
    }
}