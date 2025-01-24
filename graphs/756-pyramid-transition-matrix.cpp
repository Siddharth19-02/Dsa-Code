// M-1 
class Solution {
    unordered_map<string, bool> result;
public:

    bool dfs(unordered_map< string , vector<char> >&mp, string str)
    {
        if(str.size() == 1)
            return true;

        
        vector<string>allPossibleWords;
        allPossibleWords.push_back("");

        for(int i=0;i<str.size()-1;i++)
        {
            string key = str.substr(i,2);

            if(mp.find(key) == mp.end() )
                return false;

            vector<char> &combinations = mp[key];
            vector<string>currAllPossibleWords;

            for(char ch : combinations)
            {
                for(string curr : allPossibleWords)
                {
                    curr += ch;
                    currAllPossibleWords.push_back(curr);
                }
            }
            allPossibleWords = currAllPossibleWords;
        }

        for(string curr : allPossibleWords)
        {
            if(result.find(curr) != result.end())
                continue;
            
            if(dfs(mp, curr))
                return true;
            
            result[curr] = false;
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        unordered_map< string , vector<char> >mp;

        for(string &str : allowed)
        {
            string key = str.substr(0,2);

            mp[key].push_back(str[2]);
        }

        return dfs(mp, bottom);
    }
};

//M-2 

class Solution {
    unordered_map<string, bool> result;
public:

    bool dfs(unordered_map< string , vector<char> >&mp, string bottom, string str, int index)
    {
        if(bottom.size() == 1)
            return true;

        if(str.size() == bottom.size()-1)
        {
            if(result.find(str) != result.end() )
                return result[str];

            return result[str] = dfs(mp,str,"",0);
        }
        

        for(int i=index;i<bottom.size()-1;i++)
        {
            string key = bottom.substr(i,2);

            if(mp.find(key) == mp.end() )
                return false;

            vector<char> &combinations = mp[key];

            for(char ch : combinations)
            {
                if(dfs(mp,bottom, str + ch, i+1) )
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        unordered_map< string , vector<char> >mp;

        for(string &str : allowed)
        {
            string key = str.substr(0,2);
            mp[key].push_back(str[2]);
        }

        return dfs(mp, bottom,"", 0);
    }
};
