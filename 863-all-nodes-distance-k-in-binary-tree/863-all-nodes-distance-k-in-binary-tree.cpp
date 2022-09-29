/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> map;
    
    void helper(TreeNode* &root, TreeNode* target, int k, int flag, vector<int> &ans,                              unordered_map<TreeNode*, int> visited) {
        if(root == NULL)
            return;
        // cout << k << " " << root->val << endl;
        if(k == 0 && flag == 1){
            ans.push_back(root->val);
            return;
        }
        
        if(root->left) map[root->left] = root;
        if(root->right) map[root->right] = root;
        
        if(root == target || flag == 1) {
            flag = 1;
            if(k == 0){
                ans.push_back(root->val);
                return;
            }
            if(!visited[root->left]) helper(root->left, target, k-1, flag, ans, visited);
            if(!visited[root->right]) helper(root->right, target, k-1, flag, ans, visited);
            
            if(map[root] && root == target){
                // cout << k-1 << "--" << map[root]->val << endl;
                // TreeNode* x = root;
                // root = NULL;
                visited[root]++;
                helper(map[root], map[root], k-1, flag, ans, visited);
            }
        }
        else {
            helper(root->left, target, k, flag, ans, visited);
            helper(root->right, target, k, flag, ans, visited);
        }  
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map[root] = NULL;
        vector<int> ans;
        unordered_map<TreeNode*, int> visited;
        
        helper(root, target, k, 0, ans, visited);
        return ans;
    }
};