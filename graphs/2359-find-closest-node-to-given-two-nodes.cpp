class Solution {
public:
    void dfs(int parent,vector<int> &edges,vector<int> &dist,vector<bool> &visited)
    {
        visited[parent] = true;
        if(edges[parent] == -1 or visited[edges[parent]])
            return;
        dist[edges[parent]] = dist[parent] + 1;
        dfs(edges[parent],edges,dist,visited);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int>dist(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        vector<bool>visited(n,false);
        vector<bool>visited2(n,false);
        
        dist[node1] = 0;
        dist2[node2]= 0;
        
        dfs(node1,edges,dist,visited);
        dfs(node2,edges,dist2,visited2);
        
        int index = -1,maxDist = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(maxDist>max(dist[i],dist2[i]))
            {
                maxDist = max(dist[i],dist2[i]);
                index = i;
            }
        }
        return index;
    }
};
