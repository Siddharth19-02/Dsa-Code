class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int largestSum= INT_MIN;
        int sum=0;
        unordered_map<int,int>mp;
        
        int left= 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                sum += nums[i];
                mp[nums[i]]=i;
            }
            else
            {
                int pos=mp[nums[i]];
                if(pos<left)
                {
                    sum += nums[i];
                    mp[nums[i]]=i;
                }
                else
                {
                    
                    largestSum=max(largestSum,sum);
                    while(left<=pos)
                    {
                         sum -= nums[left];
                         left++;
                    }
                    sum += nums[i];
                    mp[nums[i]]= i;
                }
            }
        }
        largestSum= max(largestSum,sum);
        return largestSum;
    }
};
