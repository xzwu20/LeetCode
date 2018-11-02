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
    TreeNode* result_node;
    int max_depth = -1;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        helper(root, 0);
        return result_node;
    }
    int helper(TreeNode *p, int depth) {
        if (!p) return -1;
        if (depth > max_depth) {
            max_depth = depth;
            result_node = p;
        }
        int left_depth, right_depth;
        left_depth = helper(p->left, depth+1);
        right_depth = helper(p->right, depth+1);
        if (left_depth == max_depth && right_depth == max_depth) result_node = p;
        if (!p->left && !p->right) return depth;
            else return max(left_depth, right_depth);
    }
};