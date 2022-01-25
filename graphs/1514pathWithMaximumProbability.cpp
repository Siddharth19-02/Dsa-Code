class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        vector<bool> visited(n, 0);
        vector<double>weight(n,(double)0.0);
        
        priority_queue<pair<double,int> >pq;
        
        weight[start] = 1.0;
        
        pq.push({(double)1.0,start});
        
        while(!pq.empty())
        {
            pair<double,int> curr = pq.top();
            pq.pop();
            
            if(visited[curr.second])
                continue;
            
            visited[curr.second] = true;
            
            double prob = curr.first;
            
            for(auto x : g[curr.second])
            {
                if(!visited[x.first] and x.second*prob>weight[x.first])
                {
                    weight[x.first] = x.second*prob;
                    pq.push({weight[x.first],x.first});
                }
            }
        }
        return weight[end];
    }
};
