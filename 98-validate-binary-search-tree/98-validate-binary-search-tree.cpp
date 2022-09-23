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
    bool is_BST(TreeNode *root,long long int mini,long long int maxi){
        if(root == NULL){
            return true;
        }
        if(root->val > mini and root->val<maxi){
            bool left = is_BST(root->left,mini,root->val);
            bool right=is_BST(root->right,root->val,maxi);
            return left and right;
        }
        
            return false;
    }
    bool isValidBST(TreeNode* root) {
          long long  int mini =-9223372036854775808;
       long long  int maxi =9223372036854775807;
        return is_BST(root,mini,maxi);
    }
};