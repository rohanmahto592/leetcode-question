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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>v;
        TreeNode*temp=root;
        vector<int>v2;
        
        while(temp!=nullptr || !v.empty())
        {
            while(temp!=nullptr)
            {
                v.push(temp);
                temp=temp->left;
            }
            temp=v.top();
            v2.push_back(temp->val);
            v.pop();
            temp=temp->right;
        }
        return v2;
        
        
        
    }
};