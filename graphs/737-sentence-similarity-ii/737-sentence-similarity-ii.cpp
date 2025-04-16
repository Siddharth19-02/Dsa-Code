class Solution {
    unordered_map<string,string>parent;
    unordered_map<string,int>rank;
public:
    string findParent(string curr)
    {
        if(parent[curr] == curr)
            return curr;
        
        return parent[curr] = findParent(parent[curr]);
    }

    bool isWordPresent(string curr) 
    {
        if (parent.count(curr)) 
        {
            return true;
        }
        return false;
    }

    void unionfind(string first, string second)
    {
        string parent1 = findParent(first);
        string parent2 = findParent(second);

        if(parent1 == parent2)
            return;

        if(rank[parent1] >= rank[parent2])
        {
            rank[parent1] += rank[parent2];
            parent[parent2] = parent1;
        }
        else
        {
            rank[parent2] += rank[parent1];
            parent[parent1] = parent2;
        }
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        if(sentence1.size() != sentence2.size())
            return false;

        for(vector<string> similiarPair : similarPairs)
        {
            if (!parent.count(similiarPair[0])) 
            {
                parent[similiarPair[0]] = similiarPair[0];
                rank[similiarPair[0]] = 1;
            }

            if (!parent.count(similiarPair[1])) 
            {
                parent[similiarPair[1]] = similiarPair[1];
                rank[similiarPair[1]] = 1;
            }

            unionfind(similiarPair[0], similiarPair[1]);
        }


        for(int i = 0;i<sentence1.size();i++)
        {
            if(sentence1[i] == sentence2[i])
                continue;

            if(isWordPresent(sentence1[i]) && 
                isWordPresent(sentence2[i]) && 
                findParent(sentence1[i]) == findParent(sentence2[i]) 
            )
                continue;

            return false;
        }

        return true;
    }
};
