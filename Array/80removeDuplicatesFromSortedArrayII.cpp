class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i =1;
        int count=1;
        int start = 0;
        int n  = arr.size();
        
        if(n<=1)
            return n;

        while(i<n)
        {
            if(arr[i-1]==arr[i])
            {
                count++;
            }
            else
            {
                if(count>1)
                {
                    arr[start++] = arr[i-1];
                    arr[start++] = arr[i-1];
                }
                else 
                {
                    arr[start++] = arr[i-1];
                }
                count=1;
            }
            i++;
        }

        if(count>1)
        {
            arr[start++] = arr[n-1];
            arr[start++] = arr[n-1];
        }
        else 
        {
            arr[start++] = arr[n-1];
        }

        return start;
    }
};
