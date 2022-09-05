class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>>st;
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++)
        {
            int x1=st.top().first;
            int y1=st.top().second;
            int x2=intervals[i][0];
            int y2=intervals[i][1];
            if(x1<=x2 and y1>=x2 and y1<=y2)
            {
                st.pop();
                st.push({x1,y2});
            }
            else
            {
                if(y1>y2)
                {
                    continue;
                }
                st.push({x2,y2});
            }
            
            
            
            
            
        }
        vector<vector<int>>vs;
        while(!st.empty())
        {
            vector<int>v;
            v.push_back(st.top().first);
            v.push_back(st.top().second);
            st.pop();
            vs.push_back(v);
        }
        reverse(vs.begin(),vs.end());
        return vs;
        
    }
};