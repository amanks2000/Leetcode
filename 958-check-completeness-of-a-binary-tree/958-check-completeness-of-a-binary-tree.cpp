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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* prev = root;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                TreeNode* top = q.front();
                q.pop();
                if(top == NULL) continue;

                if(prev == NULL && top->left)
                    return false;
                q.push(top->left);
                prev = top->left;

                if(prev == NULL && top->right)
                    return false;
                q.push(top->right);
                prev = top->right;
            }
        }
        return true;
    }
};