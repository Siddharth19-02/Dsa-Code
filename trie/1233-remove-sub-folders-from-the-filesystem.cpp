class TrieNode{
    public:
    bool isEnd;
    unordered_map<string,TrieNode*>mp;;
    
    TrieNode()
    {
        isEnd = false;
        mp.clear();
    }
    
};

class Trie{
    
    private:
    TrieNode* root;
    
    public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string &str)
    {
        TrieNode* curr = root;
    
        int i = 1;
        while(i<str.size())
        {
            string partString = "";
            while(i< str.size() and str[i] != '/')
            {
                partString += str[i];
                i++;
            }
            
            if(curr->mp[partString] == NULL)
            {
                curr->mp[partString] = new TrieNode();
            }
            curr = curr->mp[partString];
            i++;
        }
        curr->isEnd = true;
    }
    
    void searchAll(TrieNode* curr, string res , vector<string> &result)
    {
        
        for(auto x : curr->mp)
        {
            
            string addedResult =  '/' + x.first;
            
            if(x.second->isEnd)
            {
                result.push_back(res + addedResult);
            }
            else
            {
                searchAll(x.second , res + addedResult, result);
            }
        }
    }
    
    void search(string &res , vector<string> &result)
    {
        TrieNode* curr = root;
        
        searchAll(curr, res, result);
    }
    
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        vector<string> result;
        
        Trie t;
        
        for(int i=0;i<folder.size();i++)
        {
            t.insert(folder[i]);
        }
        
        string curr = "";
        t.search(curr, result);
        
        return result;
    }
};
