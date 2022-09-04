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
    // static bool comp(pair<int,int>&p1,pair<int,int>&p2)
    // {
    //     if(p1.first==p2.first)
    //     {
    //         if (p1.second<=p2.second)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>pq;
        pq.push({root,{0,0}});
        while(!pq.empty())
        {
            auto p=pq.front();
            pq.pop();
            TreeNode*z=p.first;
            pair<int,int>pair=p.second;
            int a=p.second.first;
            int b=p.second.second;
            mp[b][a].push_back(z->val);
            if(z->left)
            {
                
                pq.push({z->left,{a+1,b-1}});
            }
            if(z->right)
            {
                
                pq.push({z->right,{a+1,b+1}});
            }
            
            
        }
        vector<vector<int>>ans;
        for (auto c : mp) {
        vector<int> col;
        for(auto r : c.second){
            //sort before filling
            sort(r.second.begin(), r.second.end());
            //this line simply takes data from the given vector and adds it
            //to col vector ie data of all vectors(each in each row) in a given column
            //are appended into single vector col
            col.insert(col.end(), r.second.begin(), r.second.end());
        }
        //push current column
        ans.push_back(col);
    }
    return ans;
        
        
        
        
        
    }
};