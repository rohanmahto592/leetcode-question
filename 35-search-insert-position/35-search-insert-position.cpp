class Solution {
public:
    int findsearch(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans+1;
    }
    int searchInsert(vector<int>& nums, int target) {
        return findsearch(nums,target);
    }
};