class Solution {
public:
    bool checkValidString(string s) {
        
        int minParenthesis = 0;
        int maxParenthesis = 0;
        
        for(char ch : s)
        {
            if(ch == '(')
            {
                minParenthesis++;
                maxParenthesis++;
            }
            else if(ch == ')')
            {
                minParenthesis = max(0,minParenthesis-1);
                maxParenthesis--;
            }
            else
            {
                minParenthesis = max(0,minParenthesis-1);
                maxParenthesis++;
            }
            
            if(maxParenthesis < 0)
                return false;
        }
        
        return (minParenthesis == 0);
    }
};
