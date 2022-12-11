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
    int helper(TreeNode* root, int& sum) {
        if(root == NULL)
            return 0;
        
        int lsum = helper(root->left, sum);
        int rsum = helper(root->right, sum);
        if(lsum < 0)
            lsum = 0;
        if(rsum < 0)
            rsum = 0;

        int tot = lsum + rsum + root->val;
        sum = max(sum, tot);
        
        return root->val + max(lsum, rsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int tot = helper(root, sum);
        return sum;
    }
};