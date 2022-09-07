class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;//[1,2]
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(mid==nums.size()-1)
            {
                return nums[0];
            }
            if(mid==0)
            {
                return min(nums[low],nums[high]);
            }
            
            if( mid>0 and mid<nums.size()-1 and nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            {
                return min(nums[mid-1],nums[mid+1]);
            }
            else if( mid>0 and nums[mid]>nums[mid-1] and nums[mid]>nums[0])
            {
                low=mid+1;
            }
            else if( mid>0 and nums[mid]>nums[mid-1] and nums[mid]<nums[0])
            {
                high=mid-1;
            }
            else
            {
                return nums[mid];
            }
        }
        return -1;
    }
};