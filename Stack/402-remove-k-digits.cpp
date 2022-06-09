class Solution {
    private:
        stack<char>s;
public:
    string removeKdigits(string nums, int k) {
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and s.top()>nums[i] and k!=0)
            {
                s.pop();
                k--;
            }
            
            if(s.empty() and nums[i]=='0')
                continue;
            else
                s.push(nums[i]);
        }
        
        while(!s.empty() and k>0)
        {
            s.pop();
            k--;
        }
        
        if(s.empty())
        {
            return "0";
        }
        
        string str = "";
        
        while(!s.empty())
        {
            str = s.top() + str;
            s.pop();
        }
        
        return str;
    }
};
