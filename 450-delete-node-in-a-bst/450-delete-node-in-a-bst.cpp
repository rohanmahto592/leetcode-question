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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
            return root;
            
            
        }
        else if(root->val == key){
            if(root->left == NULL and root->right ==NULL){
                delete root;
                return NULL;
            }
            else if(root->left== NULL and root->right!=NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->left!= NULL and root->right==NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode*temp=root->right;
               
                while(temp->left)
                {
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
                return root;
                
            }
        }
        else
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
       return root;
    }
};