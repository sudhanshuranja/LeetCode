class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.length();
        int cols = n / rows;
        
        // Step 1: Build matrix
        char[][] mat = new char[rows][cols];
        int idx = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText.charAt(idx++);
            }
        }
        
        // Step 2: Read diagonally
        StringBuilder result = new StringBuilder();
        
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            
            while (i < rows && j < cols) {
                result.append(mat[i][j]);
                i++;
                j++;
            }
        }
        
        // Step 3: Remove trailing spaces
        int end = result.length() - 1;
        while (end >= 0 && result.charAt(end) == ' ') {
            end--;
        }
        
        return result.substring(0, end + 1);
    }
}