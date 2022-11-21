class Solution {
public:
    int minimumFuel(int src,vector<int> adj[],vector<bool> &visited,long long &minimumCost,int distanceFar,int seats)
    {
        visited[src] = true;
        
        int personsTillNow = 0;
        
        for(int children : adj[src])
        {
            if(!visited[children])
            {
                int personsComing = minimumFuel(children,adj,visited,minimumCost,distanceFar+1,seats);
                personsTillNow += personsComing;
                if(personsTillNow >= seats)
                {
                    minimumCost += distanceFar;
                    minimumCost += seats;
                    personsTillNow -= seats;
                }
            }
        }
        
        if(src == 0)
            minimumCost += personsTillNow;
        
        return personsTillNow+1;
    
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        vector<int>adj[n+1];
        
        for(int i = 0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<bool>visited(n+1,false);
        
        long long minimumCost = 0;
        long distanceFar = 0;
        
        
        minimumFuel(0,adj,visited,minimumCost,distanceFar,seats);
        
        return minimumCost;
    }
};
