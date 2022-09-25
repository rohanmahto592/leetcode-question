class Solution {
public:
    bool findword(vector<vector<char>>& board,int i, int j,int n, int m,string&word, int c)
    {
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='-1')
        {
            return false;
        }
       
        if(board[i][j]==word[c])
        {
            c++;
             if(c==word.length())
                {
                    return true;
                }
            char ch=board[i][j];
            board[i][j]='-1';
        bool l=findword(board,i,j-1,n,m,word,c);
        bool r=findword(board,i,j+1,n,m,word,c);
        bool up=findword(board,i-1,j,n,m,word,c);
        bool down=findword(board,i+1,j,n,m,word,c);
            board[i][j]=ch;
        return l+r+up+down;
        }
        return false;
       
    }
        
        
        
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c=0;
                bool check=findword(board,i,j,n,m,word,c);
                if(check==true)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};