class Solution {
public:
    bool dfs(int parent,vector<vector<int>>& graph,vector<int> &memo,vector<bool> &isinstack,vector<bool> &visited)
    {
        visited[parent] = true;
        isinstack[parent] = true;
        bool ans = true;

        for(int children : graph[parent])
        {
            if(memo[children] != -1)
            {
                ans = (ans==true)&&memo[children];
            }
            else if(!visited[children])
            {
                if(!dfs(children,graph,memo,isinstack,visited))
                    ans = false;  
            }
            else if(isinstack[children] == true)
                ans = false;
        }
        isinstack[parent] = false;
        memo[parent] = ans;
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> memo(n,-1);
        vector<bool> isinstack(n,false);
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs(i,graph,memo,isinstack,visited);
        
        vector<int>res;
        
        for(int i=0;i<n;i++)
            if(memo[i] == 1)
                res.push_back(i);
        
        return res;
    }
};
