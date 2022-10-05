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
        else{
            TreeNode *t=node;
            TreeNode *a=new TreeNode(v);
            a->left=t->left;
            TreeNode *b=new TreeNode(v);
            b->right=t->right;
            t->left=a;
            t->right=b;
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