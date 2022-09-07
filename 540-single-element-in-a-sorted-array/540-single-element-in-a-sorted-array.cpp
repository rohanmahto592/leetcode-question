class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int xx=0;
            for(auto x:nums)
            {
                xx=xx^x;
            }
            return xx;
        }
};