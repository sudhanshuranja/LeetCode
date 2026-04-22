class Solution {
    public int numSquares(int n) {
        
        if(isSquare(n)) return 1;

        while(n % 4 == 0) n /= 4;

        // If reduced n is 7 mod 8 => answer is 4
        if(n % 8 == 7) return 4;

        // Check if it can be written as sum of two squares
        for(int i = 1; i * i <= n; i++) {
            if(isSquare(n - i*i)) return 2;
        }

        return 3;
    }

    private boolean isSquare(int x) {
        int r = (int)Math.sqrt(x);
        return r*r == x;
    }
}