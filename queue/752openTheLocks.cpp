class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_map<string,int>mp;
        
        for(auto x : deadends)
                mp[x]++;
        
        queue<string>q;
        q.push("0000");
        int count = 0;
        unordered_set<string>s;
        
        char a = '0';
        a += (char)1;
        cout<<a;

        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                string curr = q.front();
                q.pop();
                
                if(mp.find(curr)!=mp.end())
                    continue;
                
                if(s.find(curr)!=s.end())
                    continue;
                
                s.insert(curr);
                
                if(curr==target)
                    return count;
                
                for(int j=0;j<4;j++)
                {
                    string now = curr;
                    if(now[j]=='9')
                    {
                        now[j] = '0';
                        
                    }
                    else
                    {
                        now[j] += 1;
                    }
                    q.push(now);
                    
                    
                    now  = curr;
                    if(now[j]=='0')
                    {
                        now[j] = '9';
                    }
                    else
                    {
                        now[j] -= 1;
                    }
                    q.push(now);
                }
            }
            count++;
        }
        
        return -1;
    }
};
