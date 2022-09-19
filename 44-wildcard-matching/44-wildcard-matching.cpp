class Solution {
public:
    bool matching(string &s,string &p,int n, int m,vector<vector<int>>&dp)
    {
        if(n<0 and m<0)
        {
            return true;
        }
         if(m<0 and n>=0)
        {
            return false;
        }
        if(n<0 and m>=0)
        {
            for(int j=m;j>=0;j--)
            {
                if(p[j]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
    
        
        if(s[n]==p[m] || p[m]=='?')
        {
            return dp[n][m]= matching(s,p,n-1,m-1,dp);
            
        }
        else if(p[m]=='*')
        {
            return dp[n][m]= matching(s,p,n-1,m,dp)+matching(s,p,n,m-1,dp);
        }
        else
        {
            return false;
        }
    }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return matching(s,p,s.length()-1,p.length()-1,dp);
        
    }
};