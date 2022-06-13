class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(auto x : nums)
            count += (x==1)?1:0;
        
        int size = count;
        int currOnes = 0;
        int maxOnes = 0;
        for(int i=0;i<size;i++)
        {
            currOnes += (nums[i]==1)?1:0;
        }
        maxOnes = max(maxOnes,currOnes);
       
        for(int i=0;i<nums.size();i++)
        {
            currOnes -= (nums[i]==1)?1:0;
            currOnes += (nums[(i+size)%n]==1)?1:0;
            maxOnes = max(maxOnes,currOnes);
        }
        
        return count - maxOnes;
    }
};
