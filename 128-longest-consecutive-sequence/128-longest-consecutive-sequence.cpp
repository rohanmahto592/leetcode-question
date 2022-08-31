class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto z:nums)
        {
            st.insert(z);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)!=st.end())
            {
                continue;
            }
            else
            {
                
                int z=nums[i];
                int count=0;
                while(st.find(z)!=st.end())
                {
                    count++;
                    z=z+1;
                }
                maxi=max(maxi,count);
                
            }
        }
        return maxi;
        
    }
};