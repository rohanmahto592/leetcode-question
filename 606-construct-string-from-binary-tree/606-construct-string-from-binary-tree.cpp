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
     
    string tree2str(TreeNode* root) {
        if(root==nullptr)
            return "";
       if(root->left==nullptr and root->right==nullptr)
       {
           return to_string(root->val);
       }
        string str = to_string(root->val);
        // if(root->left!=nullptr)
            str += "(" + tree2str(root->left) + ")";
        if(root->right)
            str += "(" + tree2str(root->right) + ")";
        return str;
    }
};