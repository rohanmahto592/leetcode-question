/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
        string str = "";
    string serialize(TreeNode *root)
    {
        if(root==nullptr)
        {
            return str;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *z = q.front();
            q.pop();
            if (z == nullptr)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(z->val) + ',');
            }
            if (z != nullptr)
            {
                q.push(z->left);
                q.push(z->right);
            }
        }
        return str;
    }

   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data.size()==0)
        {
            return nullptr;
        }
        cout << data << endl;
        queue<TreeNode*> qt;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        qt.push(root);
        while (!qt.empty())
        {
            TreeNode *temp, *left=nullptr, *right = nullptr;
            temp = qt.front();
            qt.pop();
            getline(s, str, ',');
            if (str != "#")
            {
                left = new TreeNode(stoi(str));
                qt.push(left);
            }
            getline(s, str, ',');
            if (str != "#")
            {
                right = new TreeNode(stoi(str));
                qt.push(right);
            }
            temp->left=left;
            temp->right=right;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));