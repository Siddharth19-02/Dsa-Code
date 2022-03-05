class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<=2)
            return 0;
        
        int diff = nums[1] - nums[0];
        
        int count = 0;
        int prev = 0;
        
        for(int i=1;i<n-1;i++)
        {
            int curr_diff = nums[i+1] - nums[i];
            
            if(curr_diff != diff)
            {
                diff = curr_diff;
                prev = i;
            }
            
            if(prev!=i)
            {
                count += (i-prev);
            }
        }
        return count;
    }
};
