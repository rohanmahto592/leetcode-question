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
class BSTIterator {
public:
   stack<TreeNode*>st;
    void push(TreeNode*root)
    {
        if(root)
        {
            st.push(root);
            push(root->left);
        }
        
    }
    BSTIterator(TreeNode* root) {
       
       push(root);
    }
    
    int next() {
        TreeNode*z=st.top();
        st.pop();
        push(z->right);
        return z->val;
        
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */