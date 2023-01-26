class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<wall.size();i++)
        {
            int sum = 0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        
        int minBricks = wall.size();
        int n = wall.size();
        
        for(auto x : mp)
        {
            minBricks = min(minBricks,n-x.second);
        }
        
        return minBricks;
    }
};
