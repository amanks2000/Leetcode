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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, maxi = INT_MIN, res = 0;

        while(!q.empty()) {
            level++;
            int sz = q.size(), sum = 0;

            for(int i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();
                sum += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            if(sum > maxi) {
                maxi = sum;
                res = level;
            }
        }
        return res;
    }
};