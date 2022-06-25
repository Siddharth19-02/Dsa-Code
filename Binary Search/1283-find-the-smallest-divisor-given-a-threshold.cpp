class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int left = 1, right = 1e6, mid, sum;
        while (left < right) {
            mid = (left + right) / 2, sum = 0;
            for (int i : arr)
                sum += (i + mid - 1) / mid;
            if (sum > threshold)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
        

};
