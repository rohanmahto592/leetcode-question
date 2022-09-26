class Solution {
public:
    static bool comp(string &s1,string&s2)
    {
        return s1.length()<s2.length();
    }
    bool check(string &s1,string &s2)
    {
        if(s1.length()-1!=s2.length())
        {
            return false;
        }
        int i=0;
        int j=0;
        while(i<s1.length())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==s1.length() and j==s2.length())
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
      sort(words.begin(),words.end(),comp);  
        vector<int>dp(words.size(),0);
        int globalmaxi=0;
        for(int i=0;i<words.size();i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]))
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=maxi+1;
            globalmaxi=max(globalmaxi,dp[i]);
        }
        return globalmaxi;
    }
};