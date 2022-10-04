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
    //convert root->val into strings
    string arrow ="->"; 
    void createPath(TreeNode* root, string str, vector<string>&v){
        if(root && !root->left && !root->right) {
            string temp = to_string(root->val);
            if(str.size()) str+=arrow;
            str+=temp;
            // str.push_back(root->val);
            v.push_back(str);
            str.erase(temp.length());
        }
        if(!root) return;
        if(str.size()) str+=arrow;
        string temp = to_string(root->val);
        // str.push_back(root->val);
        str+=temp;
        createPath(root->left,str,v);
        createPath(root->right,str,v);
        // str.pop_back();
        str.erase(temp.length());
        // str.erase(arrow.length());
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        createPath(root,"",v);
        return v;
    }
};