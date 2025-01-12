class Solution {
public:
    string minRemoveToMakeValid(string str) {
        
        int len = str.length();
        
        stack<int>s;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
            {
                s.push(i);
            }
            else if(str[i] == ')')
            {
                if(!s.empty() )
                {
                    s.pop();
                }
                else
                {
                    str[i] = '#';
                }
            }
        }
        
        while(!s.empty())
        {
            str[s.top()] = '#';
            s.pop();
        }
        
        str.erase(remove(str.begin(),str.end(),'#'),str.end());
        
        return str;
    }
};
