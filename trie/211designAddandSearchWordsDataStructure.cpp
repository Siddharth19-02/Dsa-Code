class trieNode{
    public:
    trieNode* arr[26];
    bool isEnd;
    trieNode()
    {
        for(int i=0;i<26;i++)
        {
            arr[i] = NULL;
        }
        isEnd = false;
    }
};

class trie{
    public:
    trieNode* root;
    trie()
    {
        root = new trieNode();
    }
    
    void addWord(string str)
    {
        trieNode* curr = root;
        
        for(int i=0;i<str.length();i++)
        {
            if(curr->arr[str[i]-'a']==NULL)
            {
                curr->arr[str[i]-'a'] = new trieNode();
            }
            curr = curr->arr[str[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool searchWord(trieNode* curr,string str)
    {
        if(str.length()==0)
        {
            if(curr and curr->isEnd)
                return true;
            return false;
        }
        
        if(str[0]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(curr->arr[i]!=NULL)
                {
                    if(searchWord(curr->arr[i],str.substr(1)) )
                        return true;
                }
            }
        }
        else 
        {
            if(curr->arr[str[0]-'a']!=NULL)
            {
                if(searchWord(curr->arr[str[0]-'a'],str.substr(1)) )
                  return true;
            }
        }
        return false;
    }
    
    bool search(string word)
    {
        trieNode* curr = root;
        return searchWord(curr,word);
    }
    
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    trie* t;
    WordDictionary() {
        t = new trie();
    }
    
    void addWord(string word) {
        t->addWord(word);
    }
    
    bool search(string word) {
        return t->search(word);
    }
};
