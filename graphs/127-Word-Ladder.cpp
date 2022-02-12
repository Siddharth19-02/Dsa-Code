class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s(wordList.begin(),wordList.end());
        
        if(s.find(beginWord)!=s.end())
            s.erase(beginWord);
        
        if(s.find(endWord)==s.end())
            return 0;
        
        if(beginWord==endWord)
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int k=0;k<size;k++)
            {
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++)
                {
                    char now = curr[i];
                    for(char j='a';j<='z';j++)
                    {
                        curr[i] = j;
                        
                        if(curr==endWord)
                            return count+1;
                        
                        if(s.find(curr)==s.end())
                            continue;
                        s.erase(curr);
                        q.push(curr);
                    }
                    curr[i] = now;
                }
            }
            count++;
        }
        return 0;
    }
};
