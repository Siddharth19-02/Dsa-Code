class Solution {
public:
    vector<string> expand(string s) {
        vector<string>result;
        result.push_back("");

        int i = 0;

        while(i<s.size())
        {
            string curr = "";
            while(i<s.size() and s[i] != '{')
            {
                curr += s[i++];
            }

            if(curr.size() > 0)
            {
                for(string &str : result)
                {
                   str += curr;
                }
            }
            else
            {
                vector<string>newResult;
                i++;
                while(s[i] != '}')
                {
                    if(s[i] == ',')
                    {
                        i++;
                    }
                    
                    char ch = s[i++];

                    for(int point = 0;point<result.size();point++)
                    {
                        newResult.push_back(result[point] + ch);
                    }
                }
                i++;
                result = newResult;
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
