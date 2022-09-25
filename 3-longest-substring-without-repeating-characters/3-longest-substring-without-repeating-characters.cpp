class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int maxi = 0;
            int j = 0;
            int i = 0;
            unordered_map<char, int> mp;
            while (j < s.length())
            {
                mp[s[j]]++;
                if (mp[s[j]] <= 1) {
                    maxi=max(maxi,j-i+1);
                    j++;
                    
                }
                else
                {
                    while(mp[s[j]]!=1)
                    {
                        mp[s[i]]--;
                        i++;
                    }
                    maxi=max(maxi,j-i+1);
                    j++;
                }
            }
            return maxi;
        }
};