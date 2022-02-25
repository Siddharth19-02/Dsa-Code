class trieNode{
    public:
    int isEnd;
    trieNode* vec[26];
    trieNode(){
        for(int i=0;i<26;i++)
        {
            vec[i] = NULL;
        }
        isEnd = false;
    }
};

class trie{
    public:
    trieNode* t;
    trie(){
        t = new trieNode();
    }
    
    void insert(string word) {
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
        }
        temp->isEnd=true;
    }
    
    bool search(string word,string &str) {
         trieNode* temp=t;
        for(int i=0;i<word.length();i++)
        {
            if(temp->vec[word[i]-'a']==0)
                return false;
            str += word[i];
            temp=temp->vec[word[i]-'a'];
            if(temp->isEnd)
                return true;
        }
        return temp->isEnd;
    }
    
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie t;
        for(auto x : dictionary)
        {
            t.insert(x);
        }
        string res="";
        
        stringstream ss(sentence);
        
        string word="";
        
        while(ss>>word)
        {
            string str = "";
            if(t.search(word,str))
            {
                res += str;
            }
            else
            {
                res += word;
            }
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
