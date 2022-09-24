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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        stack<TreeNode*> s;
        
        while(!q.empty()) {
            TreeNode* front;
            int n;
            vector<int> v;
            if(count%2 == 0) 
                n = q.size() - s.size();
            else 
                n = s.size();

            for(int i = 0; i < n; i++) {
                if(count%2 == 0) {
                    front = q.front();
                    q.pop();
                    v.push_back(front->val);
                    if(front->left != NULL) {
                        s.push(front->left);
                        q.push(front->left);
                    }
                    if(front->right != NULL) {
                        s.push(front->right);
                        q.push(front->right);
                    }
                }
                else {
                    front = s.top();
                    s.pop();
                    v.push_back(front->val);
                    front = q.front();
                    q.pop();
                    if(front->left != NULL) q.push(front->left);
                    if(front->right != NULL) q.push(front->right);
                }
            }
            count++;
            ans.push_back(v);
        }
        
        return ans;
    }
};