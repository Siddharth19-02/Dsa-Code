class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int>ans(n,0);

        int leftOnes = 0, rightOnes = 0;
        int leftSum = 0, rightSum = 0;

        for(int i=0;i<n;i++)
        {
            ans[i] += leftSum;
            leftOnes += (boxes[i] == '1');
            leftSum += leftOnes;

            ans[n-i-1] += rightSum;
            rightOnes += (boxes[n-i-1] == '1');
            rightSum += rightOnes;
        }

        return ans;
    }
};
