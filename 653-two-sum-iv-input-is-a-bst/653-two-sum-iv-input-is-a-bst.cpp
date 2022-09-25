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
     void find(TreeNode*root,int k,set<int>&m,int &p)
    {
        if(root==nullptr)
        {
            return;
        }
        if(m.find(k-root->val)!=m.end())
        {
            p=1;
        }
        else
        {
            m.insert(root->val);
        }
        find(root->left,k,m,p);
         find(root->right,k,m,p);
        
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>m;
        int p=0;
        find(root,k,m,p);
        return p;
        
    }
};