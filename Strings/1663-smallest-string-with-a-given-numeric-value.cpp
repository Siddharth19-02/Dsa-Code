class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string str = "";
        
        while(n>0)
        {
            if((k-n+1)>=26)
            {
                str += "z";
                k -= 26;
            }
            else
            {
                str += char(96 + k -n+1);
                k = k - (k-n+1);
            }
            n--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
