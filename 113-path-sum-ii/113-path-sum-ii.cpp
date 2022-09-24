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
    void findsum(vector<vector<int>>&finals,TreeNode*root,int target,vector<int>vc)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->left==nullptr and root->right==nullptr)
        {
             if(target==root->val)
                {
                 vc.push_back(root->val);
                    finals.push_back(vc);
                    return;
                } 

        }
       
        
        
        vc.push_back(root->val);
        target-=root->val;
        findsum(finals,root->left,target,vc);
        findsum(finals,root->right,target,vc);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>finals;
        vector<int>vc;
        findsum(finals,root,targetSum,vc);
        return finals;
    }
};