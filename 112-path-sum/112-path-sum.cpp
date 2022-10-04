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
    bool hasPath(TreeNode* root, int targetSum) {
        if(root && root->left==NULL && root->right==NULL && (targetSum-root->val==0)) return true;
        if(!root) return false;
        if(hasPath(root->left,targetSum-root->val)||hasPath(root->right,targetSum-root->val))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return hasPath(root,targetSum);
        
    }
};