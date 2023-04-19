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
    int res = 0, cnt = 0;
    unordered_map<TreeNode*, int> mp;
    vector<vector<int>> dp;

    int longestZigZag(TreeNode* root) {
        // dir -> 0 : left, dir -> 1 : right
        countNodes(root);
        dp.resize(cnt + 1, vector<int>(3, -1));
        inorder(root);
        return res;
    }

    void countNodes(TreeNode* root) {
        if(root == NULL) return;

        countNodes(root->left);
        mp[root] = cnt;
        cnt++;
        countNodes(root->right);
    }

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);
        res = max(res, solve(2, root));
        inorder(root->right);
    }

    int solve(int dir, TreeNode* root) {
        if(root == NULL) return 0;

        int node = mp[root];
        
        if(dp[node][dir] != -1) return dp[node][dir];

        int ans = 0;
        if(dir == 2) {
            // first node
            int sm1 = solve(0, root->left);
            int sm2 = solve(1, root->right);
            ans = max(sm1, sm2);
        } 
        else if(dir) ans = 1 + solve(0, root->left);
        else ans = 1 + solve(1, root->right);

        return dp[node][dir] = ans;
    }
};