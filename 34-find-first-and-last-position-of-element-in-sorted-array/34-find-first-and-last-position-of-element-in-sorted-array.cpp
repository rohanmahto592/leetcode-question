class Solution {
public:
    
    int binarysearch1(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            
            
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
    int binarysearch2(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            
            
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int a=binarysearch1(nums,target);
        int b=binarysearch2(nums,target);
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};