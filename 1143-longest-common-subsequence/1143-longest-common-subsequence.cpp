class Solution {
public:
    int longest(string &s1,string &s2,int n, int m,vector<vector<int>>&dp )
    {
        if(n==0 or m==0)
        {
            return 0;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+longest(s1,s2,n-1,m-1,dp);
        }
        else
        {
            return dp[n][m]= max(longest(s1,s2,n,m-1,dp),longest(s1,s2,n-1,m,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return longest(text1,text2,text1.length(),text2.length(),dp);
    }
};