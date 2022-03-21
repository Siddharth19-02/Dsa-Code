class Solution {
public:
    vector<int> partitionLabels(string str) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]] = i;
        }
        
        int start = 0;
        int end = 0;
        
        vector<int>vec;
        
        for(int i=0;i<str.length();i++)
        {
            int pos = mp[str[i]];
             end = max(end,pos);
            if(i==end)
            {
                vec.push_back(end -start);
                start = end;
            }
        }
        vec[0]+= 1;
        return vec;
    }
};
