class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        vector<int>arr(n,0);
        stack<int>s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!s.empty() and temperatures[i]>temperatures[s.top()])
            {
                int x = s.top();
                s.pop();
                
                arr[x] = i-x;
            }
            
            s.push(i);
        }
        return arr;
    }
};
