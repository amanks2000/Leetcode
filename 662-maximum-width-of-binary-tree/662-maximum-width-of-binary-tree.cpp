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
    int widthOfBinaryTree(TreeNode* root) {
        long ans = 0;
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int n = q.size();
            vector<long> v;
            long mini = q.front().second;
            for(int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long idx = p.second - mini;
                v.push_back(idx);
                
                if(node->left != NULL) q.push({node->left, 2*idx + 1});
                if(node->right != NULL) q.push({node->right, 2*idx + 2});
            }
            // cout << v[n-1] << " " << v[0] << endl;
            ans = max(ans, v[n-1] - v[0]);
        }
        int a = ans + 1;
        return a;
    }
};