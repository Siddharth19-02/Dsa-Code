class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<long,int>mp;
        
        long sum = 0;
        
        int maxLength = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            if(sum == k)
            {
                maxLength = i+1;
            }
            
            if(mp.find(sum-k)!=mp.end())
            {
                maxLength = max(maxLength,i-mp[sum-k]);
            }
            
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            
        }
        return maxLength;
    }
};
