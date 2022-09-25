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
    int i=0;
    TreeNode * create(vector<int>&p , vector<int>&q, int s, int e)
    {

        if(s>e )
        {
            return nullptr;
        }
        
        TreeNode * node=new TreeNode(p[i]);
        if (s == e ) {
            i++;
            return node;
        }
        int index=-1;
        for( int j=s;j<=e;j++)
        {
            if(p[i]==q[j])
            {
                index=j;
                break;
            }
        }
        i++;
        node->left=create(p,q,s,index-1);
        node->right=create(p,q,index+1,e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode * root=create(preorder,inorder,0,preorder.size()-1);
        return root;
        
    }
};