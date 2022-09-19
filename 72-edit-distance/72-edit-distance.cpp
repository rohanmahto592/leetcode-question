class Solution {
public:
    int edit(string &s,string &t,int n,int m,vector<vector<int>>&dp)
  {
      if(n<0 and m<0)
      {
          return 0;
      }
      if(n<0 and m>=0)
      {
          return m+1;
      }
      if(n>=0 and m<0)
      {
          return n+1;
      }
      
      if(dp[n][m]!=-1)
      {
          return dp[n][m];
      }
      if(s[n]==t[m])
      {
          return dp[n][m]=edit(s,t,n-1,m-1,dp);
      }
      else
      {
          //replace
          int a=1+edit(s,t,n-1,m-1,dp);
          //delete
          int b=1+edit(s,t,n-1,m,dp);
          //insert
          int c=1+edit(s,t,n,m-1,dp);
          return dp[n][m]=min(a,min(b,c));
      }
  }
    int minDistance(string s, string t) {
    vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return edit(s,t,s.length()-1,t.length()-1,dp);
    }
};