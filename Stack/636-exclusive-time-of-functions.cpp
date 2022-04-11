class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int>vec(n,0);
        stack<int>s;
        int lastExecutableTime = 0;
        
        for(int i=0;i<logs.size();i++)
        {
            string curr = logs[i];
            bool flag = false;
            int j = 0;
            int startingNumber =0;
            int endingNumber =0;
            while(j<curr.length() and curr[j]!=':')
            {
                startingNumber = startingNumber*10 + (curr[j]-'0');
                j++;
            }
            j++;
            
            if(curr[j]=='s')
            {
                flag = true;
            }
            
            while(j<curr.length() and curr[j]!=':')
            {
                j++;
            }
            j++;
            
            while(j<curr.length())
            {
                endingNumber = endingNumber*10 + (curr[j]-'0');
                j++;
            }
            
            if(flag)
            {
                if(!s.empty())
                {
                    int cu = s.top();
                    vec[cu] += endingNumber - lastExecutableTime ;
                    lastExecutableTime = endingNumber;
                }
                s.push(startingNumber);
            }
            else
            {
                int first = s.top();
                vec[first] += endingNumber - lastExecutableTime +1;
                s.pop();
                lastExecutableTime  = endingNumber+1;
            }
            
        }
        return vec;
    }
};
