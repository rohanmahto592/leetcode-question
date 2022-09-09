class Solution
{
    static bool comp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
        {
            return v1[1]>v2[1];
        }
        else
        {
            return v1[0]<v2[0];
        }
    }
    public:
        int numberOfWeakCharacters(vector<vector < int>> &properties)
        {
            sort(properties.begin(),properties.end(),comp);
            stack<vector < int>> st;
            st.push(properties[0]);
            int count=0;
            for (int i = 1; i < properties.size(); i++)
            {
                while (st.size() and st.top()[0] < properties[i][0] and st.top()[1] < properties[i][1]) {
                    st.pop();
                    count++;
                    
                }
                st.push(properties[i]);
                    
            }
            return count;
        }
    
};