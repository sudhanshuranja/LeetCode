class BSTIterator {
public:
    TreeNode* curr, *pred;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        int ans;
        while(curr!=NULL) {
            if(curr->left!=NULL) {
                pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr) pred = pred->right;
                if(pred->right==NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                if(pred->right==curr) {
                    pred->right = NULL;
                    ans = curr->val;
                    curr = curr->right;
                    break;
                }
            } else {
                ans = curr->val;
                curr = curr->right;
                break;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return curr!=NULL;
    }
};