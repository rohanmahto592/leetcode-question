class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    if(j==nums2.size())
                    {
                        v.push_back(-1);
                        break;
                    }
                    else
                    {
                        int p=j+1;
                        while(p<nums2.size())
                        {
                            if(nums2[p]>nums1[i])
                            {
                                v.push_back(nums2[p]);
                                break;
                            }
                            p++;
                        }
                        if(p==nums2.size())
                        {
                            v.push_back(-1);
                            break;
                        }
                    }
                    
                }
            }
            
        }
        return v;
        
    }
};