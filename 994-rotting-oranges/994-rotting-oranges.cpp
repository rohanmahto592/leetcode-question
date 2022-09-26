class Solution {
public:
    bool checked(int i,int j,vector<vector<int>>&grid,int n, int m)
    {
        if(i>=0  and j>=0 and i<n and j<m and grid[i][j]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({i,j});
                }
            }
        }
        int  cnt=0;
        while(!pq.empty())
        {
            int size=pq.size();
            bool check=false;
            for(int i=0;i<size;i++)
            {
            pair<int,int>pz=pq.front();
              pq.pop();
                int x=pz.first;
                int y=pz.second;
                bool check1=checked(x-1,y,grid,n,m);
                if(check1==true)
                {
                    grid[x-1][y]=2;
                    check=true;
                    pq.push({x-1,y});
                }
                bool check0=checked(x+1,y,grid,n,m);
                if(check0==true)
                {
                    grid[x+1][y]=2;
                    check=true;
                     pq.push({x+1,y});
                }
                 bool check2=checked(x,y-1,grid,n,m);
                if(check2==true)
                {
                    grid[x][y-1]=2;
                    check=true;
                     pq.push({x,y-1});
                }
                 bool check3=checked(x,y+1,grid,n,m);
                if(check3==true)
                {
                    grid[x][y+1]=2;
                    check=true;
                     pq.push({x,y+1});
                }
                
            }
            if(check==true)
            {
                cnt++;
            }
           
            
        }
        for(int i=0;i<n;i++)
          {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                        return -1;
                }
            }
           
        return cnt;
        
    }
};