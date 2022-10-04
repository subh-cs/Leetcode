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
    void numVec(string str,vector<int>&v,TreeNode* root){
        if(root && !root->left &&!root->right){
            char temp = root->val+'0';
            str.push_back(temp);
            int num = stoi(str);
            str.pop_back();
            v.push_back(num);
            return;
        }
        if(!root) return;
        char temp = root->val+'0';
        str.push_back(temp);
        numVec(str,v,root->left);
        numVec(str,v,root->right);
        str.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int>v;
        numVec("",v, root);
        int sum = accumulate(begin(v),end(v),0);
        return sum;
    }
};