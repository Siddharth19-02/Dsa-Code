class Solution {
public:
    string encode(int num) {
        
        string result = "";

        while(num>0)
        {
            int ans = num%2;

            result += (ans == 1)?'0':'1';

            num = (num-1)/2;

        }

        reverse(result.begin(), result.end());
        return result;
    }
};
