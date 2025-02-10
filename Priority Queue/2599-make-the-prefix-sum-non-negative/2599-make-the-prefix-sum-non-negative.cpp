class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int> >pq;
        int count = 0;
        long sum = 0;

        for(int num : nums)
        {
            if(num<0)
                pq.push(num);

            sum += num;

            if(sum<0)
            {
                while(!pq.empty() and sum<0)
                {
                    int minElement = pq.top();
                    pq.pop();
                    cout<<minElement<<endl;

                    sum -= minElement;
                    count++;
                }
            }
        }

        return count;
    }
};
