class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        
        if(n<=1)
            return n;
        int j=0;
        int count = 1;
        int i=0;
        for(i=1;i<n;i++)
        {
            if(chars[i]==chars[i-1])
            {
                count++;
            }
            else
            {
                if(count==1)
                {
                    chars[j] = chars[i-1];
                    j++;
                }
                else
                {
                    chars[j++] = chars[i-1]; 
                    for(char x : to_string(count))
                    {
                        chars[j++] = x;
                    }
                }
                count = 1;
            }
        }
        
        if(count==1)
        {
            chars[j] = chars[i-1];
            j++;
        }
        else
        {
            chars[j++] = chars[i-1]; 
            for(char x : to_string(count))
            {
                chars[j++] = x;
            }
        }
        return j;
    }
};
