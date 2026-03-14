class Solution {

    String ans = "";
    int count = 0;

    public String getHappyString(int n, int k) {
        dfs(n, k, new StringBuilder());
        return ans;
    }

    void dfs(int n, int k, StringBuilder curr) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                ans = curr.toString();
            }
            return;
        }

        char[] chars = {'a', 'b', 'c'};

        for (char ch : chars) {
            if (curr.length() == 0 || curr.charAt(curr.length() - 1) != ch) {
                curr.append(ch);
                dfs(n, k, curr);
                curr.deleteCharAt(curr.length() - 1);
            }
        }
    }
}