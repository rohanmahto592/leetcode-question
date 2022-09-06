/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool Findprune(TreeNode *root)
        {
           
           if(root==nullptr)
           {
               return false;
           }
            bool l = Findprune(root->left);
            bool r = Findprune(root->right);
            if (l==false and r==false and root->val==0)
            {
                root->left=nullptr;
                root->right=nullptr;
                return false;
            }
            else if(l==false and r==false and root->val==1)
            {
                root->left=nullptr;
                root->right=nullptr;
                return true;
            }
            else if(l==false and r==true)
            {
                root->left=nullptr;
                return  true;
            }
            else if(l==true and r==false)
            {
                root->right=nullptr;
                return true;
            }
          
            return true;
            
        }
    TreeNode* pruneTree(TreeNode *root)
    {
        bool x = Findprune(root);
        if(x==false)
        {
            root=nullptr;
        }
        return root;
    }
};