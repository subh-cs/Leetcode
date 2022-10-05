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
    void addRow(TreeNode* root,int currLevel,int depth,int val){
        if(!root) return;
        if(currLevel==depth-1){
            TreeNode *tempLeft = new TreeNode(val);
            TreeNode *tempRight = new TreeNode(val);
            tempLeft->left = root->left;
            tempRight->right = root->right;
            root->left  = tempLeft;
            root->right = tempRight;
        }
        addRow(root->left,currLevel+1,depth,val);
        addRow(root->right,currLevel+1,depth,val);
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //special case
        if(depth==1){
            TreeNode * tempRoot = root;
            root = new TreeNode(val);
            root->left = tempRoot;
         }
        else{
            addRow(root,1,depth,val);
        }
        return root;
    }
};