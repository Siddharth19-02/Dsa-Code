class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        
        int first = 0;
        int second = 1;
        
        int max_count = 0;
        int curr_max_count_element = arr[0];
        
        while(second<n)
        {
            if(arr[first]<arr[second])
            {
                max_count = 1;
                curr_max_count_element = arr[second];
            }
            else
            {
                max_count++;
                int temp = arr[first];
                arr[first] = arr[second];
                arr[second] = temp;
            }
            first++;
            second++;
            if(max_count == k)
                return curr_max_count_element;
        }
        return curr_max_count_element;
    }
};
