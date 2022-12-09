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
    int preorder(TreeNode* root, int mini, int maxi) {
        if(root == NULL) 
            return maxi - mini;
        
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        int left = preorder(root->left, mini, maxi);
        int right = preorder(root->right, mini, maxi);
        return max(right, left);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        return preorder(root, root->val, root->val);
    }
};