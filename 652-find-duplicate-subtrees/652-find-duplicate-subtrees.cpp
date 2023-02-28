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
    vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    
    string helper(TreeNode* root) {
        if(root == NULL) 
            return "%";

        string leftAns = helper(root->left);
        string rightAns = helper(root->right);
        // creating path as a string
        string cur = to_string(root->val) + "%" + leftAns + "%" + rightAns;    

        if(mp[cur] == 1)
            ans.push_back(root);
        
        mp[cur]++;
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s = helper(root);
        return ans;
    }
};