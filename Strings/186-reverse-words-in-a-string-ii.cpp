class Solution {
public:
    void reverseWord(vector<char> &s,int left,int right)
    {
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        
        int left = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                reverseWord(s,left,i-1);
                left = i+1;
            }
        }
        reverseWord(s,left,s.size()-1);
    }
};
