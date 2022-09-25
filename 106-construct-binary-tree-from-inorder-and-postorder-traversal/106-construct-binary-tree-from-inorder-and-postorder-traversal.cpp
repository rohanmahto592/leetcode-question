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
    int i;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int start,int end)
    {
        
        if(start>end)
        {
            return nullptr;
        }
        TreeNode* temp=new TreeNode(postorder[i]);
            if(start==end)
            {
                i--;
                return temp;
            }
        int index=-1;
        for(int j=start;j<=end;j++)
        {
            if(postorder[i]==inorder[j])
            {
                index=j;
                break;
            }
        }
        i--;
        temp->right=build(inorder,postorder,index+1,end);
        temp->left=build(inorder,postorder,start,index-1);
        return temp;
        
        
        
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        i=postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1);
        
    }
};