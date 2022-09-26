class Solution {
public:
    void dfs(vector<int>&visited,vector<int>adj[],int parent)
    {
        visited[parent]=1;
        for(auto x:adj[parent])
        {
            if(visited[x]==-1)
            {
                dfs(visited,adj,x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j< isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }
            }
        }
        vector<int>visited(n,-1);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                cnt++;
                dfs(visited,adj,i);
            }
        }
        return cnt;
        
    }
};