class Solution {
    bool traverse(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return true;
        }
        bool flag1=traverse(root->left,v);
        if(v.size()>0&&v[v.size()-1]>=root->val){
            return false;
        }
        v.push_back(root->val);
        bool flag2=traverse(root->right,v);
        if(flag1&&flag2){
            return true;
        }
        return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        return traverse(root,v);
    }
};