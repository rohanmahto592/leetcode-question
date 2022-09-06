class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>v;
        for(int i=0;i<nums2.size();i++)
        {
            while(st.size() and st.top()<nums2[i])
            {
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(auto x:nums1)
        {
            if(mp.find(x)!=mp.end())
            {
                v.push_back(mp[x]);
            }
            else
            {
                v.push_back(-1);
            }
        }
        return v;
        
        
    }
};