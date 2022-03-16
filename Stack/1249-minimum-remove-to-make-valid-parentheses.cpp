class Solution {
public:
    string minRemoveToMakeValid(string str) {
        
        int len = str.length();
        
        stack<string>s;
        
        string curr = "";
        
        string result = "";
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=')' and str[i]!='(')
            {
                curr += str[i];
            }
            else if(str[i]=='(')
            {
                s.push(curr);
                curr = "";
                s.push("(");
            }
            else
            {
                string now = "";
                s.push(curr);
                while(!s.empty() and s.top()!="(")
                {
                    now = s.top() + now;
                    s.pop();
                }
                if(!s.empty() and s.top()=="(")
                {
                    now = s.top() + now + ")";
                    s.pop();
                }
                s.push(now);
                curr ="";
            }
        }
        
        s.push(curr);
        
        while(!s.empty())
        {
            if(s.top()=="(")
            {
                s.pop();
            }
            else
            {
                result = s.top() + result;
                s.pop();
            }
        }
        
        
        return result;
    }
};
