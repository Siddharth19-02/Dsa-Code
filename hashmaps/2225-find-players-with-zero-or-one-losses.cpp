class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>winner;
        map<int,int>oneMatchLoser;
        
        for(auto curr : matches)
        {
            int first = curr[0];
            int second= curr[1];
            
            if(oneMatchLoser.find(first) == oneMatchLoser.end())
                winner[first]++;
            
            if(winner.find(second)!=winner.end())
            {
                winner.erase(second);
            }
            oneMatchLoser[second]++;
        }
        
        vector<vector<int>> res;
        
        vector<int> first;
        for(auto x : winner)
            first.push_back(x.first);
        
        vector<int> second;
        for(auto x : oneMatchLoser)
            if(x.second == 1)
                second.push_back(x.first);
        
        res.push_back(first);
        res.push_back(second);
        
        return res;
    }
};
