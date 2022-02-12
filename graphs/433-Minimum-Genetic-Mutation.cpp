class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>s(bank.begin(),bank.end());
        
        int steps = 0;
        
        if(start==end)
            return steps;
        
        queue<string>q;
        q.push(start);
        
        vector<string>visited;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                string curr = q.front();
                q.pop();
                
                if(curr==end)
                    return steps;
                
                for(string str : s)
                {
                    int count = 0;
                    for(int j=0;j<curr.length();j++)
                    {
                        if(str[j]!=curr[j])
                            count++;
                    }
                    if(count==1)
                    {
                        q.push(str);
                        visited.push_back(str);
                    }
                    
                }
                
                for(auto x: visited)
                    s.erase(x);
                visited.clear();
            }
            steps++;
        }
        return -1;
    }
};
