class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>vc(arr.size());
        int xors=0;
        vector<int>finals;
        for(int i=0;i<arr.size();i++)
        {
            xors^=arr[i];
            vc[i]=xors;
        }
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(a>0)
            {
                int p=vc[b]^vc[a-1];
                finals.push_back(p);
            }
            else if(a==0)
            {
                finals.push_back(vc[b]);
            }
        }
        return finals;
        
    }
};