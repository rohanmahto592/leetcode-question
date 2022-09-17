class Solution {
public:
    bool findtarget(vector<int>&nums,int target)
    {
        int n=nums.size();
        bool dp[n+1][target+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    dp[i][j]=true;
                }
                else
                {
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                    }
                    else
                        
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto z:nums)
        {
            sum+=z;
        }
        if(sum%2!=0)
        {
            return false;
        }
        return findtarget(nums,sum/2);
        
    }
};