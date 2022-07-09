class Solution {
public:
    int jump(vector<int>& nums) {
        
        int count = 0;
        
        if(nums.size() == 1)
            return 0;
        
        int currMaxJump = nums[0];
        int maxJump = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(currMaxJump == 0)
            {
                currMaxJump = maxJump - i + 1;
                maxJump = 0;
                count++;
            }
            
            if(currMaxJump <= 0 and maxJump==0)
                return -1;
            
            maxJump = max(maxJump,i+nums[i]);
            currMaxJump--;
        }
        
        return count+1;
        
    }
};
