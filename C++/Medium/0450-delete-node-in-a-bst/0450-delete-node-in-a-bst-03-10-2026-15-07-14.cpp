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

    TreeNode* findMin(TreeNode* root){
        while(root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root) return NULL;

        if(key < root->val)
            root->left = deleteNode(root->left, key);

        else if(key > root->val)
            root->right = deleteNode(root->right, key);

        else{
            // case 1: no left child
            if(!root->left)
                return root->right;

            // case 2: no right child
            if(!root->right)
                return root->left;

            // case 3: two children
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};