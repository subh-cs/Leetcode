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

TreeNode* f(int l,int r,int &idx,vector<int>&in,vector<int>&post){
    if(l>r) return nullptr;
    int mid = l;while(post[idx]!=in[mid]) mid++;
    TreeNode* root = new TreeNode(in[mid]);idx--;
    root->right = f(mid+1,r,idx,in,post);
    root->left = f(l,mid-1,idx,in,post);
    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
       int idx=in.size()-1; return f(0,idx,idx,in,post);
    }
};