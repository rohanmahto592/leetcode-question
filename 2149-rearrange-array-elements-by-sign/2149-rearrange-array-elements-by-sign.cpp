class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>finals;
        int i=0;
        int j=0;
        int n=nums.size();
        bool flag1,flag2;
        while(i<n or j<n)
        {
            flag1=flag2=false;
            while(i<n and nums[i]<0)
            {
                i++;
                flag1=true;
            }
            while(j<n and nums[j]>0)   
            {
                j++;
                flag2=true;
            }
            finals.push_back(nums[i++]);
            finals.push_back(nums[j++]);
            if(i==n or j==n)
            {
                break;
            }
          
            
        }
        return finals;
        
    }
};