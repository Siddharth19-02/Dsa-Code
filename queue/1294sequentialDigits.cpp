class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>x;
        
        queue<long>q;
        
        for(long i=1;i<=8;i++){
            q.push(i);
        }
        
        while(!q.empty())
            {
            long curr = q.front();
            q.pop();
            if(curr>=low and curr<=high)
            x.push_back(curr);
            if(curr*10>1000000000)
                continue;
            
            int last=curr%10;
            if(last==9)
                continue;
            
            curr = curr*10+(last+1);
            if(curr<=high)
            q.push(curr);
        }
        
        return x;
        
    }
};
