class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n-1;
        int j=m-1;
        int i=n-1;
        while(i>=0 and j>=0)
        {
            if(nums1[j]<=nums2[i])
            {
                nums1[len--]=nums2[i--];
            }
            else
            {
                nums1[len--]=nums1[j--];
            }
        }
        while(i>=0)
        {
            nums1[len--]=nums2[i--];
        }
        
        
    }
};