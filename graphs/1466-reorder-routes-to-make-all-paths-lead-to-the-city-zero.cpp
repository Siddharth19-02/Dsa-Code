class Solution {
public:
    void dfs(int curr,vector<pair<int,int> > adj[],int parent, int &count)
    {

        for(auto & [children,sign] : adj[curr])
        {
            if(children != parent)
            {
                count += sign;
                dfs(children,adj,curr,count);
            }
            
        }
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int,int> >adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        
        int count = 0;
        
        dfs(0,adj,-1,count);
        
        return count;
    }
};
