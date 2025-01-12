class Solution {
public:
    bool canBeValid(string s, string locked) {

        if(s.size()%2 != 0)
            return false;
        
        int pmin = 0;
        int pmax = 0;

        for(int i=0;i<s.size();i++)
        {
            if(locked[i] == '1' && s[i] == '(')
            {
                pmin++;
                pmax++;
            }
            else if(locked[i] == '1' && s[i] == ')')
            {
                pmin = max(0,pmin-1);
                pmax--;
            }
            else
            {
                pmin = max(0, pmin-1);
                pmax++;
            }

            if(pmax<0)
                return false;
        }

        return (pmin == 0 );
    }
};
