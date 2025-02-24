class Solution {
public:
    string singleDigit(vector<int> &freq)
    {
        string result = "";




        while(freq['f' - 'a']>0)
        {
            result += '5';
            freq['f' - 'a']--;
            freq['i' - 'a']--;
        }


        return result;
    }

    string originalDigits(string s) {
        string result = "";

        vector<int>freq(26,0);
        vector<int>digit(10, 0);

        for(int i=0;i<s.size();i++)
        {
            freq[s[i] - 'a']++;
        }

        digit[0] = freq['z' - 'a'];
        digit[2] = freq['w' - 'a'];
        digit[4] = freq['u' - 'a'];
        digit[6] = freq['x' - 'a'];
        digit[8] = freq['g' - 'a'];

        digit[3] = freq['t' - 'a'] - digit[2] - digit[8];
        digit[5] = freq['f' - 'a'] - digit[4];
        digit[7] = freq['s' - 'a'] - digit[6];
        
        digit[1] = freq['o' - 'a'] - digit[0] - digit[2] -digit[4];
        digit[9] = freq['i' - 'a'] - digit[5] - digit[6] -digit[8];

        for (int i = 0; i <= 9; i++) 
        {
            result.append(digit[i], '0' + i);
        }

        return result;
    }
};
