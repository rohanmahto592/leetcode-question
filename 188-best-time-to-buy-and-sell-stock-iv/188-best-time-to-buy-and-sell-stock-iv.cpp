class Solution {
public:
    int sellstock(int idx, vector<int> &prices,int flag, vector<vector<vector<int>>>&dp,int cap)
        {
            if (idx == prices.size() or cap==0)
            {
                return 0;
            }
            if(dp[idx][flag][cap]!=-1)
            {
                return dp[idx][flag][cap];
            }
            
            if (flag==1)
            {
               return dp[idx][flag][cap]= max(-prices[idx] + sellstock(idx + 1, prices, 0,dp,cap), sellstock(idx + 1, prices, 1,dp,cap));
            }
            else
            {
               return dp[idx][flag][cap]=max(prices[idx]+sellstock(idx+1,prices,1,dp,cap-1),sellstock(idx+1,prices,0,dp,cap));
            }
        }
    int maxProfit(int k, vector<int>& prices) {
            int idx=0;
            int n=prices.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
            return sellstock(idx,prices,1,dp,k);
    }
};