class Solution {
public:
    bool dfs(vector<int>adj[],int start,bool* visited,bool* isinstack)
    {
        visited[start]=true;
        isinstack[start]=true;

        for(auto x:adj[start])
        {
            if(visited[x]==false &&dfs(adj,x,visited,isinstack))
            return true;
            else if(isinstack[x])
            return true;
        }
        isinstack[start]=false;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[N];
	     for(int i=0;i<prerequisites.size();i++)
	     {
	         int x=prerequisites[i][0];
	         int y=prerequisites[i][1];
	         adj[y].push_back(x);
	     }
	     
	     bool* visited=new bool[N];
	     bool* isinstack=new bool[N];
	    for(int i=0;i<N;i++)
	    {
	        visited[i]=false;
	        isinstack[i]=false;
	    }
	     
	     for(int i=0;i<N;i++)
	     {
	         if(!visited[i])
	         {
	             if(dfs(adj,i,visited,isinstack))
	             return false;
	         }
	     }
	     return true;
    
        
    }
};
