class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        
        for(int now : tasks)
            mp[now]++;
        
        int count = 0;
        
        for(auto curr : mp)
        {
            if(curr.second == 1)
                return -1;
            
            count += (curr.second/3);
            if(curr.second%3>0)
                count++;
        }
        return count;
    }
};
