##m-1
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            if(nums[i] == 0)
                continue;
            else
                nums[i] += nums[i-1];
        }
        
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i] == 0)
                continue;
            else
                nums[i] = max(nums[i],nums[i+1]);
        }
        
        for(int i =0;i<n;i++)
        {
            cout<<nums[i]<<" ";
        }
        
        int maxAns = 0;
        for(int i = 0;i < n ;i++)
        {
            if(nums[i]==0)
            {
                int ans = 1 + ((i+1)<n?nums[i+1]:0) + ((i-1>=0)?nums[i-1]:0);
                maxAns = max(ans,maxAns);
            }
        }
        return (maxAns == 0)?n:maxAns;
    }
};

##m-2

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        
        int maxDistance = 0;
        bool isAllowed = false;
        
        while(right<n)
        {
            if(nums[right] == 1)
                right++;
            else
            {
                maxDistance = max(maxDistance,right-left);
                if(isAllowed)
                {
                    while(nums[left] == 1)
                        left++;
                    left++;
                }
                isAllowed = true;
                right++;
            }
        }
        maxDistance = max(maxDistance,right-left);
        return maxDistance;
    }
};
