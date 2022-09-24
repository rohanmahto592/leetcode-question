class Solution {
public:
    int combination(int amount,vector<int>coins,int n,vector<vector<int>>&dp)
    {
        if(dp[amount][n]!=-1)
        {
            return dp[amount][n];
        }
        if(n==0 and amount==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(amount==0)
        {
            return 1;
        }
        
       
        if(coins[n-1]<=amount)
        {
            return dp[amount][n]= combination(amount-coins[n-1],coins,n,dp)+combination(amount,coins,n-1,dp);
        }
        else
        {
            return dp[amount][n]= combination(amount,coins,n-1,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
       return combination(amount,coins,n,dp);
        
    }
};