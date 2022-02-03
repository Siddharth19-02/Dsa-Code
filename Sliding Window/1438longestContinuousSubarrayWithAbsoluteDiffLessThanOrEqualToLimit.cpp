class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int>low,high;
        
        int start = 0,end = 0;
        
        int max_length = 1;
        
        int n = nums.size();
        
        while(end<n)
        {
            while(!low.empty() and nums[end]<low.back())
                low.pop_back();
            
            while(!high.empty() and nums[end]>high.back())
                high.pop_back();
            
            low.push_back(nums[end]);
            high.push_back(nums[end]);
            
            while(high.front()-low.front()>limit)
            {
                if(nums[start]==high.front())
                    high.pop_front();
                if(nums[start]==low.front())
                    low.pop_front();
                
                start++;
            }
            max_length = max(max_length,end-start+1);
            end++;
        }
        return max_length;
    }
};
