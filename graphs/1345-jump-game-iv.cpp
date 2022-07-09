class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<bool>visited(n,false);
        
        queue<int>q;
        q.push(0);
        
        unordered_map<int,vector<int> >mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        int count = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                int index = q.front();
                q.pop();

                if(index==n-1)
                    return count;

                if(visited[index])
                    continue;

                visited[index]=true;

                vector<int> curr = mp[arr[index]];
                if(index+1<n)
                    curr.push_back(index+1);
                if(index-1>=0)
                    curr.push_back(index-1);
                
                for(int j=0;j<curr.size();j++)
                {
                    if(!visited[curr[j]])
                    {
                        q.push(curr[j]);
                    }
                }
                curr.clear();
                mp[arr[index]] = curr;
            }
            count++;
            
        }
            
        return -1;
    }
};
