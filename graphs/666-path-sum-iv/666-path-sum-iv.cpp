class Solution {
public:
    bool dfs(int root, unordered_map<int,int> &mp, int currentSum, int &sum)
    {
        if(mp.find(root) == mp.end())
        {
            return true;
        }

        currentSum += mp[root];

        int leftValue  = (root/10+1)*10 + (root%10)*2 -1;
        int rightValue  = (root/10+1)*10 + (root%10)*2 ;
        
        bool left = dfs(leftValue, mp, currentSum, sum);
        bool right = dfs(rightValue, mp, currentSum, sum);

        if(left and right)
            sum += currentSum;

        return false;
    }

    int pathSum(vector<int>& nums) {
        unordered_map<int,int >mp;

        for(int num : nums)
        {
            int depth = num/100;
            int position = (num%100)/10;
            int value = num%10;

            mp[depth*10 + position] = value;
        }

        int sum = 0;
        int currentSum = 0;

        dfs(11, mp, currentSum, sum);

        return sum;
    }
};
