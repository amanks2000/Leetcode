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
    unordered_map<int, int> inPos, postPos;
    int n;

    TreeNode* helper(int s1, int e1, vector<int>& inorder, 
    int s2, int e2, vector<int>& postorder) {
        if(s1 > e1 || s2 > e2) return NULL;
        if(s1 == e1 && s2 == e2) return (new TreeNode(postorder[e2]));

        TreeNode* root = new TreeNode(postorder[e2]);
        // Find positon of root in inOrder as root in postOrder is last element
        int pos1 = inPos[postorder[e2]];
        // Calculate size of left subtree
        int leftSize = pos1 - s1;

        root->left = helper(s1, pos1 - 1, inorder, s2, s2 + leftSize - 1, postorder);
        root->right = helper(pos1 + 1, e1, inorder, s2 + leftSize, e2 - 1, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        
        for(int i = 0; i < n; i++)
            inPos[inorder[i]] = i;

        for(int i = 0; i < n; i++)
            postPos[postorder[i]] = i;

        return helper(0, n-1, inorder, 0, n-1, postorder);
    }
};