class Solution {
public:
    void findAllStrobogrammaticNumbersOfLengthN(vector<string> &result, string curr, int start, int end)
    {
        if(start>=end)
        {
            if(start == end)
            {
                curr[start] = '0';
                result.push_back(curr);

                curr[start] = '1';
                result.push_back(curr);

                curr[start] = '8';
                result.push_back(curr);
            }
            else
            {
                result.push_back(curr);
            }
            return;
        }

        if(start != 0)
        {
            curr[start] = '0' , curr[end] = '0';
            findAllStrobogrammaticNumbersOfLengthN(result, curr, start+1, end-1);
        }

        curr[start] = '1' , curr[end] = '1';
        findAllStrobogrammaticNumbersOfLengthN(result, curr, start+1, end-1);

        curr[start] = '6' , curr[end] = '9';
        findAllStrobogrammaticNumbersOfLengthN(result, curr, start+1, end-1);

        curr[start] = '8' , curr[end] = '8';
        findAllStrobogrammaticNumbersOfLengthN(result, curr, start+1, end-1);

        curr[start] = '9' , curr[end] = '6';
        findAllStrobogrammaticNumbersOfLengthN(result, curr, start+1, end-1);
    }

    vector<string> findStrobogrammatic(int n) {
        
        vector<string>result;

        string curr;
        curr.resize(n);

        findAllStrobogrammaticNumbersOfLengthN(result, curr, 0, n-1);

        return result;
    }
};
