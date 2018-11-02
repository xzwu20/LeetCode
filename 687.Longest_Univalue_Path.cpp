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
private: 
    int helper(TreeNode *t, int &res) {
        if (!t) return 0;
        int r_left = helper(t->left, res);
        int r_right = helper(t->right, res);
        
        int d_left=0, d_right=0;
        d_left = t->left && t->val == t->left->val ? r_left+1 : 0;
        d_right = t->right && t->val == t->right->val ? r_right+1 : 0;
        
        res = max(res, d_left+d_right);
        return max(d_left, d_right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};