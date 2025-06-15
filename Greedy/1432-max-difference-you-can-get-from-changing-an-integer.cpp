class Solution {
public:
    int maxDiff(int num) {

        string s = to_string(num);
        string t = s;

        int pos = -1;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] != '9')
            {
                pos = i;
                break;
            }
        }

        if (pos != -1) 
        {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }

        pos = -1;
        for(int i = 0;i<t.size();i++)
        {
            if(t[i] != '1' and t[i] != '0')
            {
                pos = i;
                break;
            }
        }

        if (pos != -1) 
        {
            char a = t[pos];

            if(pos != 0)
                replace(t.begin(), t.end(), a, '0');
            else
                replace(t.begin(), t.end(), a, '1');
        }
        
        return stoi(s) - stoi(t);
    }
};
