class Solution {
public:
    bool cycle(int parent,vector<int>&visited,vector<int>&checker,vector<int>adj[])
  {
      visited[parent]=1;
      checker[parent]=1;
      for(auto x:adj[parent])
      {
          if(checker[x]==true and visited[x]==true)
          {
              return true;
          }
          if(visited[x]==-1)
          {
              if(cycle(x,visited,checker,adj)==true)
              {
                  return true;
              }
              
          }
      }
      checker[parent]=-1;
      return false;
  }
    void dfs(vector<int> adj[],int parent,stack<int>&st,vector<int>&visited)
	{
	    visited[parent]=1;
	    for(auto x:adj[parent])
	    {
	        if(visited[x]==-1)
	        {
	            dfs(adj,x,st,visited);
	        }
	    }
	    st.push(parent);
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited2(numCourses,-1);
        vector<int>checker(numCourses,-1);
        for(int i=0;i<numCourses;i++)
        {
            if(visited2[i]==-1)
            {
                bool check=cycle(i,visited2,checker,adj);
                if(check==true)
                {
                    return {};
                }
            }
            
        }
        vector<int>visited(numCourses,-1);
	    stack<int>st;
	    for(int i=0;i<numCourses;i++)
	    {
	        if(visited[i]==-1)
	        {
	            dfs(adj,i,st,visited);
	        }
	    }
	    vector<int>v;
	    
	    while(!st.empty())
	    {
	        
	        v.push_back(st.top());
	        st.pop();
	    }
	    return v;
        
    }
};