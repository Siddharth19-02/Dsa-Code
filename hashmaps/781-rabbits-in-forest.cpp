class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        
        unordered_map<int,int>mp;
        
        int ans = 0;
        
        for(auto x : answers)
            mp[x]++;
        
        for(auto x : mp)
        {
            int key = x.first;
            int value=x.second;
            
            if((key+1)>=value)
            {
                ans += key+1;
            }
            else
            {
                int total = (value)/(key+1);
                int left = value%(key+1);
                ans += total*(key+1);
                if(left)
                    ans += key+1;
            }
            
        }
        
        return ans;
    }
};
