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
TreeNode* f(int l, int r,int &ind, vector<int>&pre, vector<int>&in){
    if(l>r) return NULL;
    int mid = l;  // find the root from inorder
    while(in[mid] != pre[ind]) mid++;
    ind++;
    TreeNode* root = new TreeNode(in[mid]);
    root->left = f(l,mid-1,ind,pre,in);
    root->right = f(mid+1,r,ind,pre,in);
    return root;
}
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int ind = 0;
        return f(0,in.size()-1,ind,pre,in);
    }
};