class Solution
{
    public:
        void flip(int i, int j, vector<vector < char>> &board)
        {
            if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == 'X'
                or board[i][j] == '1')
            {
                return;
            }

            board[i][j] = '1';
            flip(i - 1, j, board);
            flip(i, j + 1, board);
            flip(i, j - 1, board);
            flip(i + 1, j, board);
        }
    void solve(vector<vector < char>> &board)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[0][j] == 'O')
            {
                flip(0, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
            {
                flip(i, 0, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][board[0].size() - 1] == 'O')
            {
                flip(i, board[0].size() - 1, board);
            }
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[board.size() - 1][j] == 'O')
            {
                flip(board.size() - 1, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '1')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};