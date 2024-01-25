class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode* copy = new TreeNode(root->val);
        copy->left = invertTree(root->right);
        copy->right = invertTree(root->left);
        
        return copy;
    }
};