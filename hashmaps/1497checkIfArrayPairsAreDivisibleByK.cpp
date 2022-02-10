class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        
        unordered_map<int,int>mp;
        
        for(auto x : arr)
        {
            if(x<0)
                x = (x%k)+k;
            mp[x%k]++;
        }
        
        if(mp.find(0)!=mp.end())
        {
            int a = mp[0];
            if(a%2==1)
                return false;
        }
        
        for(int i=1;i<k;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                int a = mp[i];
                int b = mp[k-i];
                if(a!=b)
                    return false;
            }
        }
        return true;
    }
};
