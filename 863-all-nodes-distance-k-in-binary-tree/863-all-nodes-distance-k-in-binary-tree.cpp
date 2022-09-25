/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool findpath(TreeNode*root,vector<TreeNode*>&v,int target)
    {
        if(root==nullptr)
        {
            return false;
        }
        v.push_back(root);
        if(target==root->val)
        {
            
            return true;
        }
        
        if(findpath(root->left,v,target))
        {
            return true;
        }
        if(findpath(root->right,v,target))
        {
            return true;
        }
        v.pop_back();
        
        return false;
    
        
    }
    void findnodes(TreeNode*root,int k,TreeNode*check,vector<int>&finals)
    {
        if(root==nullptr or root==check)
        {
            return;
        }
        if(k==0)
        {
            finals.push_back(root->val);
            return;
        }
        
        findnodes(root->left,k-1,check,finals);
         findnodes(root->right,k-1,check,finals);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*>v;
        bool a=findpath(root,v,target->val);
        
        vector<int>finals;
         int b=k;
        for(int i=v.size()-1;i>=0;i--)
        {
            TreeNode*z=v[i];
           if(b<0)
           {
               break;
           }
            findnodes(z,b,b==k?nullptr:v[i+1],finals);  
            --b;
            
        }
        return finals;
    }
};