class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            if (nums.empty())
            {
                return {};
            }
            if (nums.size() == 1 || nums.size() == 2)
            {
                return {};
            }
            sort(nums.begin(), nums.end());
            vector<vector < int>> vs;
            set<vector < int>> st;

            for (int i = 0; i < nums.size() - 2; i++)
            {
                if(i>0 and nums[i]==nums[i-1])
                {
                    continue;
                }

                int j = i + 1;
                int k = nums.size() - 1;
                while (j < k)
                {
                    if ((nums[i] + nums[j]) == -nums[k])
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        st.insert(v);
                        j++;
                        k--;
                    }
                    else if ((nums[i] + nums[j]) < -nums[k])
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            for (auto z: st)
            {
                vs.push_back(z);
            }
            return vs;
        }
};