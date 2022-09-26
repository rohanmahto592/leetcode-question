class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& mat,int n, int m)
    {
        if(i>=0 and j>=0 and i<n and j<m and mat[i][j]==-1)
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    pq.push({i,j});
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        int ans=0;
        while(!pq.empty())
        {
            int size=pq.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                pair<int,int>p=pq.front();
                pq.pop();
                int x=p.first;
                int y=p.second;
                if(check(x-1,y,mat,n,m))
                {
                    mat[x-1][y]=ans;
                    pq.push({x-1,y});
                }
                if(check(x,y+1,mat,n,m))
                {
                    mat[x][y+1]=ans;
                    pq.push({x,y+1});
                }
                if(check(x+1,y,mat,n,m))
                {
                    mat[x+1][y]=ans;
                    pq.push({x+1,y});
                }
                if(check(x,y-1,mat,n,m))
                {
                    mat[x][y-1]=ans;
                    pq.push({x,y-1});
                }
                
                
            }
           
        }
        return mat;
    }
};