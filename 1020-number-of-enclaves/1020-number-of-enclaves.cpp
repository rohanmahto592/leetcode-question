class Solution {
public:
    void flip(int i, int j, vector<vector < int>> &board)
        {
            if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == 0
                or board[i][j] == -1)
            {
                return;
            }

            board[i][j] = -1;
            flip(i - 1, j, board);
            flip(i, j + 1, board);
            flip(i, j - 1, board);
            flip(i + 1, j, board);
        }
    int numEnclaves(vector<vector<int>>& board) {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[0][j] == 1)
            {
                flip(0, j, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 1)
            {
                flip(i, 0, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][board[0].size() - 1] == 1)
            {
                flip(i, board[0].size() - 1, board);
            }
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[board.size() - 1][j] == 1)
            {
                flip(board.size() - 1, j, board);
            }
        }
        int count=0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] ==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};