class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string> > mp;
        
        for(int i=0;i<strings.size();i++)
        {
            string curr = strings[i];
            string psuedo = "";
            
            for(int j=1;j<curr.size();j++)
            {
                char x = char(((curr[j]-curr[j-1]) + 26)%26);
                psuedo += x;
            }
            
            mp[psuedo].push_back(curr);
        }
        
        vector<vector<string>> res;
        
        for(auto x : mp)
            res.push_back(x.second);
        
        return res;
    }
};
