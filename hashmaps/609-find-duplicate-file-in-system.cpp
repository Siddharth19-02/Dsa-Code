class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string> >mp;
        
        for(int i = 0;i<paths.size();i++)
        {
            string curr = paths[i];
            
            string directory = "";
            
            int j = 0;
            
            for(j=0;j<curr.size();j++)
            {
                if(curr[j]==' ')
                {
                    j++;
                    break;
                }
                else
                    directory += curr[j];
            }
            
            directory += '/';
            
            string restOfPath = "";
            string contentInfo = "";
            bool content = false;
            
            for(;j<curr.size();j++)
            {
                if(curr[j]=='(')
                {
                    content = true;
                }
                else if(curr[j] == ')')
                {
                    content = false;
                    mp[contentInfo].push_back(directory+restOfPath);
                    restOfPath = "";
                    contentInfo = "";
                }
                else if(curr[j] == ' ')
                    continue;
                else if(!content)
                {
                    restOfPath += curr[j];
                }
                else if(content)
                {
                    contentInfo += curr[j];
                }
            }
            
        }
        
        
        vector<vector<string>> res;
        
        for(auto x : mp)
        {
            if(x.second.size()>1)
                res.push_back(x.second);
        }
        
        return res;
    }
};
