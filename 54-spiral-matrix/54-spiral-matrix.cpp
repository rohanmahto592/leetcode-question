class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            vector<int> vs;
            int l1 = 0, c1 = 0, l2 = matrix.size() - 1, c2 = matrix[0].size() - 1;
            int direction = 0;

            while (l1 <= l2 and c1 <= c2)
            {
                if (direction == 0)
                {

                    for (int p = c1; p <= c2; p++)
                    {
                        vs.push_back(matrix[l1][p]);
                    }
                    l1++;
                }
                if (direction == 1)
                {
                    for (int z = l1; z <= l2; z++)
                    {
                        vs.push_back(matrix[z][c2]);
                    }
                    c2--;
                }
                if (direction == 2)
                {
                    for (int q = c2; q >= c1; q--)
                    {
                        vs.push_back(matrix[l2][q]);
                    }
                    l2--;
                }
                if (direction == 3)
                {
                    for (int r = l2; r >= l1; r--)
                    {
                        vs.push_back(matrix[r][c1]);
                    }
                    c1++;
                }
                direction = (direction + 1) % 4;
            }
            return vs;
        }
};