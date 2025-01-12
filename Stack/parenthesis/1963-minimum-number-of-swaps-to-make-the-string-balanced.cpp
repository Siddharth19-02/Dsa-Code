class Solution {
public:
    int minSwaps(string s) {
        int result = 0;
        int left = 0;

        for(char ch : s)
        {
            (ch == '[')?left +=1 : left-=1;
            if(left<0)
            {
                result += abs(left);
                left = 0;
            }
        }

        result += left;
        return (result/4) + (result%4?1:0);
    }
};
