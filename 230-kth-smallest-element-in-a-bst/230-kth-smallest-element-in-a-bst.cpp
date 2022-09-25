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
int ans;
class Solution {
public:
    void findsmallest(TreeNode*root,int k,int &n)
    {
        if(root==nullptr)
        {
            return;
        }
        findsmallest(root->left,k,n);
        n++;
        if(n==k)
        {
            ans=root->val;
        }
        findsmallest(root->right,k,n);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int n=0;
        findsmallest(root,k,n);
        return ans;
    }
};