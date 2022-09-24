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
    void pathsum(TreeNode*root,int target,vector<vector<int>>&finals,vector<int>v)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->left==nullptr and root->right==nullptr)
        {
            if(target==root->val)
            {
                v.push_back(root->val);
                finals.push_back(v);
                return;
            }
            return;
            
        }
        
        v.push_back(root->val);
        target-=root->val;
        pathsum(root->left,target,finals,v);
        pathsum(root->right,target,finals,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>finals;
        vector<int>v;
        pathsum(root,targetSum,finals,v);
        return finals;
    }
};