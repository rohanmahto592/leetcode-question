/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr)
        {
            return {};
        }
        queue<Node*>qt;
        qt.push(root);
        vector<vector<int>>finals;
        while(!qt.empty())
        {
            int size=qt.size();
            vector<int>ans;
            for(int i=0;i<size;i++)
            {
                Node*parent=qt.front();
                qt.pop();
                
                ans.push_back(parent->val);
                
                if(parent->children.size()>0)
                {
                    vector<Node*>v=parent->children;
                    for(auto z:v)
                    {
                        qt.push(z);
                    }
                }
            }
            finals.push_back(ans);
        }
        return finals;
        
    }
};