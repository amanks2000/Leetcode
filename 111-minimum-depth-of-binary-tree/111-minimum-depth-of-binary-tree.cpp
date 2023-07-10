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
    int depth(TreeNode* root) {
        if(root == NULL)
            return 1e7;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int lh = depth(root->left);
        int rh = depth(root->right);

        return min(lh, rh) + 1;
    }

    int minDepth(TreeNode* root) {
        int ans = depth(root);
        return ans == 1e7 ? 0 : ans; 
    }
};