##m-1 dfs
class Solution {
public:
    bool dfs(int src,int parent,vector<int> adj[],vector<bool> &visited)
    {
        visited[src] = true;
        
        for(int children : adj[src])
        {
            if(!visited[children])
            {
                if(!dfs(children,src,adj,visited))
                    return false;
            }
            else if(children != parent)
                return false;
        }
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool>visited(n,false);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        bool ans = dfs(0,-1,adj,visited);
        if(ans == false)
            return false;
        
        for(int i=0;i<n;i++)
            if(!visited[i])
                return false;
        
        return true;
    }
};

##m-2 using union find
