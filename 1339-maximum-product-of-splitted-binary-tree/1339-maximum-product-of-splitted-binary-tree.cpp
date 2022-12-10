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
    int mod = 1e9 + 7;

    void solve(TreeNode* root, unordered_map<TreeNode*, int>& mp, int sum, long long& ans) {
        if(root == NULL)
            return;
        long long x = mp[root];
        long long y = sum - mp[root];
        ans = max(ans, x*y);

        solve(root->left, mp, sum, ans);
        solve(root->right, mp, sum, ans);
    }

    int totSum(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if(root == NULL)
            return 0;
        int sum = root->val;
        sum += totSum(root->left, mp);
        sum += totSum(root->right, mp);

        mp[root] = sum;
        return sum;
    }

    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        int sum = totSum(root, mp);
        long long ans = 0;
        solve(root, mp, sum, ans);
        return ans % mod;
    }
};