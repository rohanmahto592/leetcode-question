class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            if (nums.size() <= 1)
            {
                return;
            }
            int j = nums.size() - 2;
            while (nums[j] >= nums[j + 1])
            {
                j--;
                if (j == -1)
                {
                    sort(nums.begin(), nums.end());
                    return;
                }
            }

            int val = j;
            
            int q;
            int mini = INT_MAX;
            for (int p = j + 1; p < nums.size(); p++)
            {
                if (nums[p] > nums[val] and nums[p] < mini)
                {
                    q = p;
                    mini = nums[p];
                }
            }
            swap(nums[q], nums[j]);
            sort(nums.begin() + j + 1, nums.end());
        }
};