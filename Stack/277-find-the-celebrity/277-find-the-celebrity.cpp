/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
        int low = 0;
        int high = n-1;
        
        while(low<high)
        {
            if(knows(low,high))
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        cout<<low<<" "<<high<<" "<<n;
        for(int i=0;i<n;i++)
        {
            if(i!=low)
                if(knows(low,i) || !knows(i,low))
                    return -1;
        }
        return low;
    }
};
