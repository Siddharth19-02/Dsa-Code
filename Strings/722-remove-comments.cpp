class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool flag = false;
        bool doubleQuotes = false;
        string curr = "";
        
        for(int i=0;i<source.size();i++)
        {
            for(int j=0;j<source[i].size();j++)
            {
                if(!flag and source[i][j]=='/' and j+1<source[i].size() and source[i][j+1] =='/')
                {
                    doubleQuotes = true;
                    break;
                }
                else if(!flag and source[i][j]=='/' and j+1<source[i].size() and source[i][j+1] =='*')
                {
                    flag = true;
                    j++;
                }
                else if(flag and source[i][j]=='*' and j+1<source[i].size() and source[i][j+1] =='/')
                {
                    flag = false;
                    j++;
                }
                else if(!flag)
                    curr += source[i][j];
            }
            
            if(doubleQuotes)
            {
                if(curr.length()>0)
                {
                    res.push_back(curr);
                }
                curr = "";
            }
            
            if(!flag and curr.length()>0)
            {
                res.push_back(curr);
                curr = "";
            }
        }
        
        return res;
    }
};
