class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>res(length,0);
        
        for(int i = 0;i < updates.size() ; i++)
        {
            if(updates[i][0]-1>=0)
            {
                res[updates[i][0]-1] -= updates[i][2];
            }
            res[updates[i][1]] += updates[i][2];
        }
        
        for(int i=length-2;i>=0;i--)
        {
            res[i] += res[i+1];
        }
        
        return res;
    }
};
