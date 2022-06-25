class Solution {
public:
    bool topology(vector<int> adj[],int start,vector<bool> &visited,vector<bool> &isinstack,stack<int> &s)
    {
        visited[start] = true;
        isinstack[start] = true;
        for(auto child : adj[start])
        {
            if(!visited[child])
            {
                if(topology(adj,child,visited,isinstack,s))
                    return true;
            }
            else if(isinstack[child])
            {
                return true;
            }
        }
        
        isinstack[start] = false;
        s.push(start);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            
            adj[y].push_back(x);
            
        }
        
        vector<bool>visited(numCourses,false);
        vector<bool>isinstack(numCourses,false);
        stack<int>s;
        vector<int> vec;
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(topology(adj,i,visited,isinstack,s))
                {
                    return vec;
                }
            }
        }
        
        while(!s.empty())
        {
            vec.push_back(s.top());
            s.pop();
        }
        return vec;
    }
};
