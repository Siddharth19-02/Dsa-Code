class Solution {
public:

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = 1;
        int high = accumulate(sweetness.begin() , sweetness.end(), 0);
        int result = INT_MIN;

        while(low<=high)
        {
            int mid = (low+high)/2;

            int count = 0;
            int sum = 0;

            for(int sweet : sweetness)
            {
                sum += sweet;
                if(sum >= mid)
                {
                    count++;
                    sum = 0;
                }
            }

            if(count > k)
            {

                result = mid;
                low = mid + 1;

            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }
};
