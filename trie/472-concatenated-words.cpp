class trie{
  public:
    bool flag;
    trie* arr[26];
    trie()
    {
        flag = false;
        for(int i=0;i<26;i++)
            arr[i] = NULL;
    }
};

class trieNode{
    public:
    trie* t;
    trieNode()
    {
        t = new trie();
    }
    
    void insert(string word)
    {
        trie* curr = t;
        for(int i=0;i<word.size();i++)
        {
            if(curr->arr[word[i]-'a']==NULL)
                curr->arr[word[i]-'a'] = new trie();
            curr = curr->arr[word[i]-'a'];
        }
        curr->flag = true;
    }
    
    bool search(string word,unordered_set<string> &s,int &count)
    {
        if(word.size()==0)
            return true;
        trie* curr = t;
        for(int i=0;i<word.size();i++)
        {
            if(curr->arr[word[i]-'a'])
            {
                curr = curr->arr[word[i]-'a'];
                if(curr->flag)
                {
                    if(search(word.substr(i+1),s,count))
                    {
                        count++;
                         return true;
                    }
                }
            }
            else
                return false;
        }
        return false;
    }
    
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string>s(words.begin(),words.end());
        vector<string>result;
        
        trieNode curr;
        
        for(int i=0;i<words.size();i++)
            curr.insert(words[i]);
        
        for(int i=0;i<words.size();i++)
        {
            int count = 0;
            if(curr.search(words[i],s,count))
            {
                if(count>1)
                    result.push_back(words[i]);
            }
        }
        
        return result;
    }
};
