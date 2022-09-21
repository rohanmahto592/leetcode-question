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
    int findmaxpathsum(TreeNode* root,int &globalmaxi)
    {
        if(root==nullptr)
        {
            return 0;
        }
        
        int a=findmaxpathsum(root->left,globalmaxi);//15
        int b=findmaxpathsum(root->right,globalmaxi);//7
        if(a<0)
        {
            a=0;
        }
        if(b<0)
        {
            b=0;
        }
        
        globalmaxi=max(globalmaxi,max(root->val+max(a,b),root->val+a+b));
        return root->val+max(a,b);
        
        

    }
    int maxPathSum(TreeNode* root) {
        int globalmaxi=INT_MIN;
        int z=findmaxpathsum(root,globalmaxi);
        return globalmaxi;
    }
};