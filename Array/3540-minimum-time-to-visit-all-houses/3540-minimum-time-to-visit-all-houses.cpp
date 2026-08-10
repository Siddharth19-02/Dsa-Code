class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        
        int n = forward.size();
        vector<long long>ford(n);
        vector<long long>back(n);
        for(int i = 1;i<n;i++)
            ford[i] = forward[i-1];
        ford[0] = forward[n-1];
        for(int i = 1;i<n;i++)
            ford[i] += ford[i-1];
        for(int i = n-2;i>=0;i--)
            back[i] = backward[i+1];
        back[n-1] = backward[0];
        for(int i = n-2;i>=0;i--)
            back[i] += back[i+1];
        long long result = 0;
        int src = 0;
        for(int i = 0;i<queries.size();i++)
        {
            int dest = queries[i];
            long long currForward = 0;
            long long currBackward = 0;
            if(dest >= src)
            {
                currForward = ford[dest] - ford[src];
            }
            else
            {
                currForward = ford[n-1] - ford[src] + ford[dest];
            }
            if(src >= dest)
            {
                currBackward = back[dest] - back[src];
            }
            else
            {
                currBackward = back[0] - back[src] + back[dest];
            }
            result += min(currForward, currBackward);
            src = dest;
        }
        return result;
    }
};
// 0 1 2
// 4 1 4
// 4 5 9
// 1 2 4
// 7 6 4
// 4 or 
// (forward[des] - forward[src] ,  back[0] - back[src] + back[dest])
// (forward[n-1] - forward[src] + forward[des]) , back[dest] - back[src]
