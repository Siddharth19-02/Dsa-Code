// we have to store the results beause dfs solution won't always guarantee the longest path 
//sometimes it may give correct ans and sometimes wrong ans also .. it can give worng ans as
// the path from where i am going i have already visited by some other node resulting in me not
// getting the correct answere so thats why we are storing result from every node to get the 
//greatest value from that path

class Solution {
public:
    bool dfs(int parent,vector<int>adj[],vector<int> &visited,vector<bool> &isinstack,int &maxLen)
    {
        visited[parent] = 1;
        isinstack[parent] = true;
        
        for(int children : adj[parent])
        {
            if(!visited[children])
            {
                if(dfs(children,adj,visited,isinstack,maxLen))
                    return true;
            }
            else if(isinstack[children])
                return true;
            visited[parent] = max(visited[parent],visited[children]+1);
        }
        maxLen = max(maxLen,visited[parent]);
        
        isinstack[parent] = false;
        return false;
    }
        
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<int> adj[n+1];
        
        for(int i=0;i<relations.size();i++)
        {
            adj[relations[i][0]].push_back(relations[i][1]);
        }
        
        vector<int>visited(n+1,false);
        vector<bool>isinstack(n+1,false);
        int maxLen = 0;
        
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
                if(dfs(i,adj,visited,isinstack,maxLen))
                    return -1;
        }
        return maxLen;
    }
};
