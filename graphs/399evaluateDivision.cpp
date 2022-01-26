class Solution {
public:
    bool dfs(string first,string second,unordered_map<string,vector<pair<string,double> >>mp,unordered_map<string,bool> &visited,double &ans)
    {
        if(first==second)
            return true;
        
        visited[first] = true;
        
        for(auto x : mp[first])
        {
            if(!visited[x.first])
            {
                if(dfs(x.first,second,mp,visited,ans))
                {
                    ans = ans*x.second;
                    visited[first] = false;
                    return true;
                }
            }
        }
        
        visited[first] = false;
        return false;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double>result;
        
        unordered_map<string,vector<pair<string,double> >>mp;
        unordered_map<string,bool> visited;
        
        for(int i=0;i<equations.size();i++)
        {
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            string first = queries[i][0];
            string second = queries[i][1];
            
            if(mp.find(first)==mp.end() or mp.find(second)==mp.end())
            {
                result.push_back(-1*((double)1.0));
                continue;
            }
            
            if(first==second)
            {
                result.push_back(double(1.0));
                continue;
            }
            double res = double(1.0);
            if(dfs(first,second,mp,visited,res))
                result.push_back(res);
            else
                 result.push_back(-1*((double)1.0));
        }
        
        return result;
    }
};
