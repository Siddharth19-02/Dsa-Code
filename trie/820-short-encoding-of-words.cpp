int ans=0;

class trienode{

public:

    char data;

    unordered_map<char, trienode*> child;

    trienode(char c){

        data=c;

    }

};

class trie{

    trienode* root;

public:

    trie(){

        root= new trienode('\0');

    }

    void insert(string s){

        trienode* temp= root;

        for(int i=s.size()-1; i>=0; i--){

            char ch=s[i];

            if(temp->child.count(ch)!=NULL){

                temp=temp->child[ch];

            }

            else{

                trienode* n= new trienode(ch);

                temp->child[ch]=n;

                temp=n;

            }

        }

    }

    void new_words(){

        for(auto i: root->child){

            dfs(i.second, 0);

        }

    }

    void dfs(trienode* temp ,int k){

        k=k+1;

        int c=0;

        for(auto i: temp->child){

            dfs(i.second, k);

            c++;

        }

        if(c==0){

            ans+=k+1;

        }

        return;

    }

};

class Solution {

public:

    int minimumLengthEncoding(vector<string>& w){

        ans=0;

        trie t;

        for(int i=0;i<w.size();i++){

            t.insert(w[i]);

        }

        t.new_words();

        return ans;

    }

};
   
