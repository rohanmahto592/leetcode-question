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
string finals;
class Solution {
public:
    TreeNode *lca(TreeNode *root,int &a,int &b){
        if(root == NULL){
            return NULL;
        }
        if(root->val==a or root->val==b){
            return root;
        }
        TreeNode *left=lca(root->left,a,b);
        TreeNode *right=lca(root->right,a,b);
        if(left!=NULL and right!=NULL){
            return root;
        }
        else if(left==NULL and right!=NULL){
            return right;
        }
        else
        {
        return left;
        }
       
    }
    void binarytreeToAnother(TreeNode *temp,int &x,string &p){
        
        if(temp == NULL){
            return;
        }
        if(temp->val == x){
            finals=p;
            return;
        }
        p+="L";
        binarytreeToAnother(temp->left,x,p);
        p.pop_back();
        p+="R";
        binarytreeToAnother(temp->right,x,p);
        p.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {   
        TreeNode *temp=lca(root,startValue,destValue);
        string p1="",p3,p4;
        binarytreeToAnother(temp,startValue,p1);
        p3=finals;
        finals="";
        binarytreeToAnother(temp,destValue,p1);
        p4=finals;
         string str(p3.length(), 'U');
      
        return str+p4;
        
    }
};