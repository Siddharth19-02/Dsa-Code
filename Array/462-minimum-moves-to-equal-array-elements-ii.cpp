class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n%2)
           n= n/2;
        else 
            n= n/2 -1;
        for(auto x : nums)
        {
            count += abs(nums[n]-x);
        }    
        return count;
    }
};
