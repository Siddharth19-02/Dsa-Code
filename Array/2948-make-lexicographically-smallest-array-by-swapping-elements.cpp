class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int>sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end(), greater<int>());

        unordered_map<int,int>groupNumberOfNumber;
        unordered_map<int, vector<int> > numbersInGroup;

        int currentGroup = 0;
        groupNumberOfNumber[sortedNums[0]] = currentGroup;
        numbersInGroup[currentGroup].push_back(sortedNums[0]);

        for(int i=1;i<sortedNums.size();i++)
        {
            if(sortedNums[i-1] - sortedNums[i] > limit)
            {
                currentGroup++;
            }
            
            groupNumberOfNumber[sortedNums[i]] = currentGroup;
            numbersInGroup[currentGroup].push_back(sortedNums[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int groupNumber = groupNumberOfNumber[nums[i]];
            nums[i] = numbersInGroup[groupNumber][numbersInGroup[groupNumber].size()-1];
            numbersInGroup[groupNumber].pop_back();
        }
        
        return nums;
    }
};
