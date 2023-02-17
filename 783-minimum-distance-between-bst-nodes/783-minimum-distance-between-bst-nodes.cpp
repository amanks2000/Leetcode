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
    int ans;

    int helper(TreeNode* root, int val) {
        if(root == NULL) return INT_MAX;

        int res = abs(root->val - val);
        return min(res, min(helper(root->left, val), helper(root->right, val)));
    }

    void preorder(TreeNode* root) {
        if(root == NULL) return;

        int cur = min(helper(root->left, root->val), helper(root->right, root->val));
        ans = min(ans, cur);
        
        preorder(root->left);
        preorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        ans = INT_MAX;
        preorder(root);
        return ans;
    }
};