class Solution
{
    public:
        int sellstock(int idx, vector<int> &prices,int flag,vector<vector<int>>&dp,int fee)
        {
            if (idx == prices.size())
            {
                return 0;
            }
            if(dp[idx][flag]!=-1)
            {
                return dp[idx][flag];
            }
            
            if (flag==1)
            {
               return dp[idx][flag]= max(-prices[idx] + sellstock(idx + 1, prices, 0,dp,fee), sellstock(idx + 1, prices, 1,dp,fee));
            }
            else
            {
               return dp[idx][flag]=max(prices[idx]-fee+sellstock(idx+1,prices,1,dp,fee),sellstock(idx+1,prices,0,dp,fee));
            }
        }
    int maxProfit(vector<int> &prices,int fee)
    {
        int idx = 0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return sellstock(idx, prices, 1,dp,fee);
    }
};