class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long>left(n,-1);
        vector<long>right(n,n);
        
        stack<int>sleft;
        stack<int>sright;
        
        for(int i=0;i<n;i++)
        {
            while(!sleft.empty() and arr[i]<arr[sleft.top()])
                sleft.pop();
            
            int x = (sleft.empty())?-1:sleft.top();
            left[i] = x;
            sleft.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!sright.empty() and arr[i]<=arr[sright.top()])
                sright.pop();
            
            int x = (sright.empty())?n:sright.top();
            right[i] = x;
            sright.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<left[i]<<" "<<right[i]<<endl;
        }
        
        long long int sum = 0;
        int mod = 1000000007;
        for(int i=0;i<n;i++)
        {
            sum = (sum%mod + ((i-left[i])*arr[i]*(right[i]-i))%mod)%mod ;
        }
        
        return sum;
    }
};
