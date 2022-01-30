class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mp;
        
        int max_length = 0;
        int start = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[fruits[i]]++;
            
            if(mp.size()>2)
            {
                while(mp.size()>2 and start<i)
                {
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0)
                        mp.erase(fruits[start]);
                    start++;
                }
            }
            int length = i - start+1;
            //cout<<length<<" "<<start<<endl;
            max_length = max(length,max_length);
        }
        return max_length;
    }
};
