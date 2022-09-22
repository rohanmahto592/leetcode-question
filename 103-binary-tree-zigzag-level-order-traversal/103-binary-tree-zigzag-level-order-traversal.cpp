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
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            if(root==nullptr)
            {
                return {};
            }
            stack<TreeNode*> q1, q2;
            q1.push(root);

            vector<vector < int>> vc;
            while (true)
            {
                bool flag1 = false, flag2 = false;
                vector<int>v;
                while (!q1.empty())
                {
                    flag1 = true;
                    TreeNode *temp = q1.top();
                    q1.pop();
                    v.push_back(temp->val);
                    if (temp->left)
                    {
                        q2.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q2.push(temp->right);
                    }
                }
                if(flag1==true)
                {
                vc.push_back(v);
                }
                
                v.clear();
                while (!q2.empty())
                {
                    flag2 = true;
                    TreeNode *temp = q2.top();
                    q2.pop();
                    v.push_back(temp->val);
                    if (temp->right)
                    {
                        q1.push(temp->right);
                    }
                    if (temp->left)
                    {
                        q1.push(temp->left);
                    }
                }
                if(flag2==true)
                {
                vc.push_back(v);
                }
                
                if (flag1 == false and flag2 == false)
                {
                    break;
                }
            }
            return vc;
        }
};