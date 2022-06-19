class trienode
{
    public:
    bool flag;
    trienode** v;
    string s;
    trienode()
    {
        v = new trienode*[26];
        for(int i=0;i<26;i++)
            v[i]=NULL;
        flag=false;
        s = "";
    }    
};

class trie
{
    public:
    trienode* root;
    trie()
    {
        root  = new trienode();
    }
    
    void add(string str)
    {
        trienode* temp = root;
        for(int i=0;i<str.length();i++)
        {
            if(temp->v[str[i]-'a']==NULL)
            {
                trienode* node = new trienode();
                temp->v[str[i]-'a'] = node;
            }
            temp = temp->v[str[i]-'a'];
        }
        temp->flag = true;
        temp->s = str;
    }
    
    void searchAll(trienode* temp,vector<string> &res)
    {
        if(res.size()>2)
            return;
        if(temp->flag)
            res.push_back(temp->s);
        
        for(int i=0;i<26;i++)
        {
            if(temp->v[i]!=NULL)
            {
                searchAll(temp->v[i],res);
            }
        }
    }
    
    void search(string str,vector<string> &res)
    {
        trienode* temp = root;
        
        for(int i=0;i<str.length();i++)
        {
            if(temp->v[str[i]-'a']==NULL)
                return;
             temp = temp->v[str[i]-'a'];
        }
        
        searchAll(temp,res);
        
    }
    
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        trie t;
        
        for(int i=0;i<products.size();i++)
        {
            t.add(products[i]);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<searchWord.length();i++)
        {
            vector<string>curr;
            t.search(searchWord.substr(0,i+1),curr);
            ans.push_back(curr);
        }
        
        return ans;
    }
};
