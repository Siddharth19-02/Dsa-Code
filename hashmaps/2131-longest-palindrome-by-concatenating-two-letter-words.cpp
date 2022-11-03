class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        int count = 0;
        int odd = false;
        
        for(int i=0;i<words.size();i++)
        {
            string curr = words[i];
            reverse(curr.begin(),curr.end());
          
            if(mp.find(curr)!=mp.end() && words[i]!=curr && mp[curr]>0 && mp[words[i]]>0)
            {
                if(mp[words[i]]==1)
                    mp.erase(words[i]);
                else
                    mp[words[i]]--;
                
                if(mp[curr]==1)
                    mp.erase(curr);
                else
                    mp[curr]--;
                
                count += 4;
            }
            else if(words[i]==curr && mp[words[i]]>0)
            {
                int freq = mp[words[i]];
                if(freq%2)
                {
                    if(!odd)
                    {
                        count += 2;
                        odd = true;
                    }
                    freq--;
                }
                count += (freq*2);
                mp.erase(words[i]);
            }
        }
        return count;
    }
};


//Method - 2

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
	vector < vector < int >>count(26, vector < int >(26));

  for (string w:words)
	{
		int i = w[0] - 'a',  j = w[1] - 'a';
		if (count[j][i])
		{
			ans += 4;
			count[j][i]--;
		}
		else count[i][j]++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (count[i][i]) return ans + 2;
	}

	return ans;
    }
};
