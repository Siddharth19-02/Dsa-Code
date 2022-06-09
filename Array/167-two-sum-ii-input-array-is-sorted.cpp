class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int>vec;
        
        int low = 0;
        int high = numbers.size()-1;
        
        while(low<high)
        {
            int sum = numbers[low] + numbers[high];
            
            if(sum==target)
            {
                vec.push_back(low+1);
                vec.push_back(high+1);
                return vec;
            }
            else if(sum<target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        
        return vec;
    }
};
