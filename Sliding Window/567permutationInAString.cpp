class Solution {
public:
    bool checkInclusion(string words, string s) {
        int arr[26] = {0};
        int arr2[26]={0};
        for(int i=0;i<words.size();i++)
        {
            arr[words[i]-'a']++;
        }
        
        if(words.length()>s.length())
            return false;
        
        int start = 0,i=0;
        int totalWords = 0;
        for(i=0;i<words.length();i++)
        {
            arr2[s[i]-'a']++;
            if(arr2[s[i]-'a']<=arr[s[i]-'a'])
                totalWords++;
        }
        
        for(i = words.length();i<s.length();i++)
        {
            if(totalWords==words.length())
            {
                return true;
            }
            
            if(arr2[s[start]-'a']<=arr[s[start]-'a'])
            {
                totalWords--;
            }
        
            arr2[s[start]-'a']--;
            start++;
            
            arr2[s[i]-'a']++;
            if(arr2[s[i]-'a']<=arr[s[i]-'a'])
                totalWords++;
        }
        if(totalWords==words.length())
        {
            return true;
        }
        return false;
    }
};
