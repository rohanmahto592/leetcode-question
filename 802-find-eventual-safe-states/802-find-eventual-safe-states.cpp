class Solution {
public:
    bool iscycle(int parent,vector<int>&visited,vector<int>&path,vector<int>&check,vector<int>adj[])
    {
        visited[parent]=1;
        path[parent]=1;
        for(auto x:adj[parent])
        {
            if(path[x]==1 and visited[x]==1)
            {
                return true;
            }
            if(visited[x]==-1)
            {
                if(iscycle(x,visited,path,check,adj)==true)
                {
                    return true;
                }
            }
        }
        check[parent]=1;
        path[parent]=-1;
        return false;
        
        
        
        
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>visited(n,-1);
        vector<int>pathvisited(n,-1);
        vector<int>check(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                bool z=iscycle(i,visited,pathvisited,check,adj);
            }
        }
        vector<int>v;
        for(int i=0;i<check.size();i++)
        {
            if(check[i]==1)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};