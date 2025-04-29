class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int maxElement = *max_element(nums.begin(),nums.end()); 
        int freq = 0;   
        int start = 0;

        for(int end = 0;end<nums.size();end++)
        {
            if(nums[end] == maxElement)
                freq++;

            while(freq >= k)
            {
                count += (nums.size() - end);
                if(nums[start++] == maxElement)
                    freq--;
            }
        }


        return count;
    }
};
