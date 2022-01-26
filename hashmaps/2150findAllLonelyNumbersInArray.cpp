class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
     
        vector<int>vec;
        
        unordered_map<int,int>mp;
        
        for(auto x : nums)
            mp[x]++;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>1)
                continue;
            
            if(mp.find(nums[i]+1)!=mp.end())
                continue;
            
            if(mp.find(nums[i]-1)!=mp.end())
                continue;
            
            vec.push_back(nums[i]);
        }
        return vec;
    }
};
