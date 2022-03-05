class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int* arr = new int[10001];
        
        for(int i=0;i<=10000;i++)
        {
            arr[i] = 0;
        }
        
        for(auto x : nums)
            arr[x]++;
        
        int maxAns = arr[1];
        
        for(int i=2;i<=10000;i++)
        {
            int currAns =  max((arr[i]*i)+arr[i-2],arr[i-1]);
            arr[i] = currAns;
            maxAns=max(maxAns,currAns);
        }
        
        return maxAns;
    }
};
