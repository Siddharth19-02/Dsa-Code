class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    int n = s.length();
    int m = t.length();
        
        
    if(abs(n-m)>1)
        return false;

    if(n-m<0)
        return isOneEditDistance(t,s);

        int count = 0;
        int i = 0;
        int j = 0;
        while(i<n and j<m)
        {
            if(s[i]!=t[j])
            {
                if(count)
                    return false;
                count++;
                if(n-m>0)
                    j--;
            }
            j++;
            i++;
        }
        if(count==0 and n==m)
            return false;
        return (count<=1);

    }
};
