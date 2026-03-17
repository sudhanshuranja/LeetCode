import java.util.*;

class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Set<Integer>> map = new HashMap<>();

        // Store reserved seats by row
        for (int[] seat : reservedSeats) {
            map.computeIfAbsent(seat[0], k -> new HashSet<>()).add(seat[1]);
        }

        int result = (n - map.size()) * 2; // rows with no reservations

        for (Set<Integer> seats : map.values()) {

            boolean left = !(seats.contains(2) || seats.contains(3) || seats.contains(4) || seats.contains(5));
            boolean right = !(seats.contains(6) || seats.contains(7) || seats.contains(8) || seats.contains(9));
            boolean middle = !(seats.contains(4) || seats.contains(5) || seats.contains(6) || seats.contains(7));

            if (left && right) {
                result += 2;
            } else if (left || right || middle) {
                result += 1;
            }
        }

        return result;
    }
}