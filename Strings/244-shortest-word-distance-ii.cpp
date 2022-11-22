class WordDistance {
    unordered_map<string,vector<int> >mp;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++)
            mp[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> first = mp[word1];
        vector<int>second = mp[word2];
        
        int minDistance = INT_MAX;
        
        int i = 0 ,j = 0;
        
        while(i<first.size() and j<second.size())
        {
            minDistance = min(minDistance,abs(first[i]-second[j]));
            if(first[i]<second[j])
                i++;
            else
                j++;
        }
        
        return minDistance;
    }
};
