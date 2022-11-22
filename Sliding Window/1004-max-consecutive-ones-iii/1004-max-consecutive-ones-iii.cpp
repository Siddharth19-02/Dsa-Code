class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int right = 0;
        int left = 0;
        
        int count = 0;
        int maxLength = 0;
        int n = nums.size();
        
        while(right<n)
        {
            if(nums[right] == 0)
                count++;
            
            if(count > k)
            {
                int length = right - left;
                maxLength = max(maxLength,length);
                while(count>k)
                {
                    if(nums[left] == 0)
                    {
                        left++;
                        count--;
                        break;
                    }
                    left++;
                }
            }
            right++;
        }
        int length = right - left;
        maxLength = max(maxLength,length);
        return maxLength;
    }
};
