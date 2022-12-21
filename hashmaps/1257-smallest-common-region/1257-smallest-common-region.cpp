class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string>mp;
        
        for(int i=0;i<regions.size();i++)
        {
            for(int j=1;j<regions[i].size();j++)
            {
                mp[regions[i][j]] = regions[i][0];
            }
        }
        
        unordered_set<string>s;
        
        while(1)
        {
            if(mp.find(region1)!=mp.end())
            {
                s.insert(region1);
                region1 = mp[region1];
            }
            else
            {
                s.insert(region1);
                break;
            }
        }
        
        while(1)
        {
            if(s.find(region2)!=s.end())
                return region2;
            else if(mp.find(region2)!=mp.end())
            {
                region2 = mp[region2];
            }
            else
                break;
        }
        
        return "";
    }
};
