class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,pair<int,vector<int>>>mp;
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            int maxi=0;
            pair<int,vector<int>>pointer;
            for(int j=i-1;j>=0;j--)
            {
                if((nums[i]%nums[j])==0 or (nums[j]%nums[i])==0 )
                {
                   
                  if(mp[nums[j]].first>maxi)
                  {
                       flag=true;
                      maxi=mp[nums[j]].first;
                      pointer=mp[nums[j]];
                      
                  }
                    
                }
            }
            if(flag==false)
            {
                vector<int>temp2;
                temp2.push_back(nums[i]);
                pair<int,vector<int>>p;
                p.first=temp2.size();
                p.second=temp2;
                mp[nums[i]]=p;//[1,{1,[1]}]
            }
            else
            {
                vector<int>vs=pointer.second;
                vs.push_back(nums[i]);
                pair<int,vector<int>>pt;
                pt.first=maxi+1;
                pt.second=vs;
                mp[nums[i]]=pt;
            }
        }
        int maxi=0;
        vector<int>finals2;
        for(auto z:mp)
        {
            pair<int,vector<int>>finals=z.second;
            if(finals.first>maxi)
            {
                maxi=finals.first;
                finals2=finals.second;
            }
            
        }
        
        return finals2;
        
    }
};