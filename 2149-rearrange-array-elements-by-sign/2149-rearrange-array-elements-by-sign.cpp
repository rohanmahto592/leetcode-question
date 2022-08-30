class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>finals;
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n and j<n)
        {
           
            while(i<n and nums[i]<0)
            {
                i++;
                
            }
            while(j<n and nums[j]>0)   
            {
                j++;
               
            }
            finals.push_back(nums[i]);
            finals.push_back(nums[j]);
            i++;
            j++;
            
          
            
        }
        return finals;
        
    }
};