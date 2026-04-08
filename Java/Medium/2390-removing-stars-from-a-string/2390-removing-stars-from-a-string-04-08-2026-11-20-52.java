class Solution {
    public String removeStars(String s) {
        StringBuilder stack = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                stack.deleteCharAt(stack.length() - 1); // pop
            } else {
                stack.append(ch); // push
            }
        }

        return stack.toString();
    }
}