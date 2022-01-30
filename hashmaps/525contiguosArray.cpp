class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxlength=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i]=-1;
        
        for(int i=0;i<nums.size();i++)
            {
            sum +=nums[i];
            if(sum==0)
                maxlength=i+1;
            
            if(mp.find(sum)==mp.end())
                {
                mp[sum]=i;

            }else{
                int length=i-mp[sum];
                maxlength=max(maxlength,length);
            }
        }
        return maxlength;
    }
};
