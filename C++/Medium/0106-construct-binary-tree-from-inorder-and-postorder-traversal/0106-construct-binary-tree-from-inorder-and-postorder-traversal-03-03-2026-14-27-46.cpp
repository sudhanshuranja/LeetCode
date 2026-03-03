/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<int,int> inorderIndex;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Build map
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int left, int right) {

        if (left > right)
            return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndex[rootVal];

        // IMPORTANT: build right first
        root->right = build(postorder, index + 1, right);
        root->left = build(postorder, left, index - 1);

        return root;
    }
};