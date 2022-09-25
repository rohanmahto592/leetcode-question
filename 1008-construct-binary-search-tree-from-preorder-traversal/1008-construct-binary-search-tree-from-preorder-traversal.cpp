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
    TreeNode*bstpreorder(TreeNode*root,int val)
    {
        if(root==nullptr)
        {
            TreeNode* t=new TreeNode(val);
            return t;
        }
        if(root->val>val)
        {
            root->left=bstpreorder(root->left,val);
        }
        else
        {
            root->right=bstpreorder(root->right,val);
        }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int n=preorder.size();
       TreeNode*temp=new TreeNode(preorder[i]);
        for(int i=1;i<n;i++)
        {
            if(preorder[i]>temp->val)
            {
                temp->right=bstpreorder(temp->right,preorder[i]);
            }
            else
            {
                temp->left=bstpreorder(temp->left,preorder[i]);
            }
        }
        return temp;
    }
};