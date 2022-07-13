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
void bfs(TreeNode* root, vector<vector<int>>&v){
    if(!root) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int>demo;
        while(n--){
            TreeNode* top=q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            demo.push_back(top->val);
        }
        v.push_back(demo);
    }
}

void dfs(TreeNode* root,int level, map<int,vector<int>>&m){
    if(!root) return;
    m[level].push_back(root->val);
    if(root->left) dfs(root->left,level+1,m);
    if(root->right) dfs(root->right,level+1,m);
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs(root,ans);
        map<int,vector<int>>m;
        dfs(root,0,m);
        vector<vector<int>>ans;
        for(auto it: m)
            ans.push_back(it.second);
        return ans;
    }
};