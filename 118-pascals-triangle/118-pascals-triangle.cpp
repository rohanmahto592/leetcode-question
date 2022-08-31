class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vs;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int>v(i+1,0);
            v[0]=1;
            v[v.size()-1]=1;
            for(int p=1;p<v.size()-1;p++)
            {
                v[p]=vs[i-1][p-1]+vs[i-1][p];
            }
            vs.push_back(v);
            
        }
        return vs;
        
    }
};