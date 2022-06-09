class trieNode{
    public:
    int isEnd;
    trieNode* vec[26];
    int sum;
    trieNode(){
        for(int i=0;i<26;i++)
        {
            vec[i] = NULL;
        }
        isEnd = false;
        sum =0;
    }
};

class trie{
    public:
    trieNode* t;
    trie(){
        t = new trieNode();
    }
    
    void insert(string word,int val) {
        trieNode* temp=t;
        int k=0;
        for(int i=0;i<word.length();i++)
        {
            if(temp->vec[word[i]-'a']==0) //create new
            {
                trieNode* newnode=new trieNode();
                temp->vec[word[i]-'a']=newnode;
            }
            temp=temp->vec[word[i]-'a'];
            temp->sum += val;
        }
        temp->isEnd=true;
    }
    
        void deleteit(string word,int val) {
        trieNode* temp=t;
        int k=0;
        for(int i=0;i<word.length();i++)
        {
            if(temp->vec[word[i]-'a']==0) //create new
            {
                trieNode* newnode=new trieNode();
                temp->vec[word[i]-'a']=newnode;
            }
            temp=temp->vec[word[i]-'a'];
            temp->sum -= val;
        }
        temp->isEnd=true;
    }
    
    int search(string word) {
         trieNode* temp=t;
        for(int i=0;i<word.length();i++)
        {
            if(temp->vec[word[i]-'a']==NULL)
                return 0;
            temp=temp->vec[word[i]-'a'];
        }
        return temp->sum;
    }
    
    
};

class MapSum {
public:
    trie *t;
    unordered_map<string,int>mp;
    MapSum() {
        t = new trie();
    }
    
    void insert(string key, int val) {
        if(mp.find(key)!=mp.end()){
           t->deleteit(key,mp[key]);
        }
        mp[key] = val;
        t->insert(key,val);
    }
    
    int sum(string prefix) {
        return t->search(prefix);
    }
};
