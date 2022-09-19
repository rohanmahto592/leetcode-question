class Solution {
public:
    int minimum(string &s1,string&s2,int n, int m,vector<vector<int>>&dp)
    {
        if(n<0 or m<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        
        if(s1[n]==s2[m])
        {
            return dp[n][m]=1+minimum(s1,s2,n-1,m-1,dp);
        }
        else
        {
            return dp[n][m]=max(minimum(s1,s2,n,m-1,dp),minimum(s1,s2,n-1,m,dp));
        }
        
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-minimum(s,s2,n-1,n-1,dp);
    }
};