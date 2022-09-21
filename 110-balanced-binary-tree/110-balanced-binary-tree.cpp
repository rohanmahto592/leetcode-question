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
 static int f;
class Solution {
    
public:
   
    
    int check(TreeNode*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left=check(root->left);
        int right=check(root->right);
        if(abs(left-right)>1)
        {
            f=0;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        f=1;
        int z=check(root);
        return f;
        
    }
};