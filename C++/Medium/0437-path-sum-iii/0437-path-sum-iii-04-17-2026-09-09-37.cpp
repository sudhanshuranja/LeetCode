/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0 ; unordered_map<long,long> map;
    void fxn(TreeNode* root, int& targetSum,long long Sum){
        if(!root) return;
        // leetcode 560 code , logic used here
        Sum += root->val;
        if(map.find(Sum - targetSum)!=map.end()){
            ans += map[Sum - targetSum];
        }
        map[Sum]++;

        fxn(root->left,targetSum,Sum);
        fxn(root->right,targetSum,Sum);
        // backtrack bcz subaaray resizes 
        map[Sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map[0] = 1;
        fxn(root,targetSum,0);
        return ans;
    }
};