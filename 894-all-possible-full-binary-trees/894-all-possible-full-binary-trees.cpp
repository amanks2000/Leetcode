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
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int n) {
        if(dp.count(n)) return dp[n];

        vector<TreeNode*> res;
        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
            return res;
        }

        for(int i = 1; i < n-1; i+=2) {
            vector<TreeNode*> leftAns = allPossibleFBT(i);
            vector<TreeNode*> rightAns = allPossibleFBT(n-i-1);

            for(auto l: leftAns) {
                for(auto r: rightAns) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return dp[n] = res;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        return solve(n);
    }
};