/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private void recursiveFun(TreeNode root, List<Integer> lst){
        if(root == null){
            return;
        }
        if(root.left == null && root.right == null){
            lst.add(root.val);
            return;
        }
        
        recursiveFun(root.left, lst);
        recursiveFun(root.right, lst);
    } 
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> lst1 = new ArrayList<>();
        List<Integer> lst2 = new ArrayList<>();
        recursiveFun(root1, lst1);
        recursiveFun(root2, lst2);

        return lst1.equals(lst2);
    }
}