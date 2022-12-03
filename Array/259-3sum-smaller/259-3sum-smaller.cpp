class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int count = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<target)
                {
                    count += (k-j);
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        
        return count;
    }
};
