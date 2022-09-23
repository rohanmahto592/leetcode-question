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
    TreeNode* balanced_bt(vector<int>& nums,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=balanced_bt(nums,s,mid-1);
        root->right=balanced_bt(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        return balanced_bt(nums,s,e);
    }
};