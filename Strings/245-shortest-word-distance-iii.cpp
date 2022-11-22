class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int firstDist = INT_MAX;
        int secondDist = INT_MAX;
        
        int minDist = INT_MAX;
        
        if(word1!=word2)
        {
            for(int i=0;i<wordsDict.size();i++)
            {
                if(wordsDict[i]==word1)
                {
                    firstDist = i;
                    minDist = min(minDist,abs(firstDist-secondDist));
                }
                else if(wordsDict[i] == word2)
                {
                    secondDist = i;
                    minDist = min(minDist,abs(firstDist-secondDist));
                }
            }
        }
        else
        {
            for(int i=0;i<wordsDict.size();i++)
            {
                if(wordsDict[i]==word1 or wordsDict[i] == word2)
                {
                    secondDist = firstDist;
                    firstDist = i;
                    minDist = min(minDist,abs(firstDist-secondDist));
                }

            }
        }
        
        
        return minDist;
        
    }
};


##solution -2 

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        long long dist = INT_MAX, p1 = dist, p2 = -dist;
        for(int i=0;i<wordsDict.size();i++){
            if(wordsDict[i] == word1) p1 = i;
            if(wordsDict[i] == word2) {
                if(word1 == word2) p1 = p2;
                p2 = i;
            }
            dist = min(dist, abs(p1 - p2));
        }
        return dist;
    }
            
};
