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
    void createVec(TreeNode*root, int targetSum, vector<int>v,vector<vector<int>>&ans){
        if(root && !root->left && !root->right){
            if(targetSum-root->val == 0) {v.push_back(root->val);ans.push_back(v);v.pop_back();}
            return; 
        }
        if(!root) return;
        v.push_back(root->val);
        createVec(root->left,targetSum-root->val,v,ans);
        createVec(root->right,targetSum-root->val,v,ans);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;vector<vector<int>>ans;
        createVec(root,targetSum, v,ans);
        return ans;
    }
};