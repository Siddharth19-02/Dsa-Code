class Solution {
    unordered_set<string>set;
public:
    bool canPermutePalindrome(string s, unordered_map<char,int>&mp) {
        int count = 0;

        for(char ch : s)
        {
            mp[ch]++;
        }

        for(auto x : mp)
        {
            if(x.second%2)
                count++;
        }

        return (count<=1);
    }

    void allPermutations(string s, int start, char ch)
    {
        if(start == s.size())
        {
            string rev = s;
            reverse(rev.begin(),rev.end());
            if(ch != '0')
                s.push_back(ch);
            
            set.insert(s + rev);
            return;
        }

        for(int i=start;i<s.size();i++)
        {
            if(i == start || s[i] != s[start])
            {
                swap(s[start], s[i]);
                allPermutations(s, start+1,ch);
                swap(s[start], s[i]);
            }
        }
    }

    vector<string> generatePalindromes(string s) {

        unordered_map<char,int>mp;
        char ch = '0';

        if(!canPermutePalindrome(s,mp) )
        {
            return {};
        }

        string curr = "";

        for(auto x : mp)
        {
            if(x.second%2 == 1)
                ch = x.first;

            for(int i=0;i<x.second/2;i++)
            {
                curr += x.first;
            }
        }

        allPermutations(curr, 0, ch);

        vector<string> result(set.begin(), set.end());
        return result;
    }
};
