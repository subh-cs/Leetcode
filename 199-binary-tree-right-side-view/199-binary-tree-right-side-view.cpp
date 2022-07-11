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
void dfs(TreeNode* root, int level, map<int,int> &m){
    if(!root) return;
    if(m.find(level)==m.end()) m.insert({level,root->val});
    dfs(root->right,level+1,m);
    dfs(root->left,level+1,m);
}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int>m;
        dfs(root,1,m);
        for(auto it: m)
            ans.push_back(it.second);
        return ans;
    }
};