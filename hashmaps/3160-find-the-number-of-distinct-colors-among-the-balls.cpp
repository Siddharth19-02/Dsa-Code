class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>colors;
        
        int distinct = 0;
        vector<int>result;

        for(vector<int> &query : queries)
        {
            int ball = query[0];
            int color = query[1];

            if(mp.find(ball) != mp.end() )
            {
                if(colors[mp[ball]] == 1)
                {
                    distinct--;
                }
                colors[mp[ball]]--;
            }


            mp[ball] = color;
            if(colors[color] == 0)
            {
                distinct++;
            }
            colors[color]++;

            result.push_back(distinct);
        }

        return result;
    }
};
