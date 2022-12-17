class Solution {
public:
    void dfs(int parent,vector<bool> &visited,vector<int>adj[])
    {
        visited[parent] = true;
        for(int children : adj[parent])
        {
            if(!visited[children])
                dfs(children,visited,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>visited(n,false);
        
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};
