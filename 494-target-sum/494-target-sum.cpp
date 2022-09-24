class Solution {
public:
    int Target(vector<int>&nums,int target,int n)
    {
        if(n==0 and target==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        int l= Target(nums,target-nums[n-1],n-1);
        int r=Target(nums,target+nums[n-1],n-1);
        return l+r;
            
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return Target(nums,target,n);
    }
};