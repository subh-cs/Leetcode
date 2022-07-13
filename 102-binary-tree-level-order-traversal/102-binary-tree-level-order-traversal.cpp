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
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int>demo;
        while(n--){
            TreeNode* top=q.front();
            q.pop();
            if(top->left!=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
            demo.push_back(top->val);
        }
        v.push_back(demo);
    }
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        bfs(root,ans);
        return ans;
    }
};