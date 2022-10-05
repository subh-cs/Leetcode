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
    void f(TreeNode* node, int depth, int v, int d){
        if(!node)return;
        if(depth<=d-2){
            f(node->left,depth+1,v,d);
            f(node->right,depth+1,v,d);
        }
        else if(depth==d-1){
            TreeNode *a=new TreeNode(v);
            TreeNode *b=new TreeNode(v);
            a->left=node->left;
            b->right=node->right;
            node->left=a;
            node->right=b;
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode * nn=new TreeNode(v);
            nn->left=root;
            return nn;
        }
        f(root,1,v,d);
        return root;
    }
};