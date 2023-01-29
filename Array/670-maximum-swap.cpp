class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        int smallIndex = -1 ,bigIndex = -1;
        int currBig = num%10, currBigIndex = n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if((str[i]-'0')>currBig)
            {
                currBig = str[i] - '0';
                currBigIndex = i;
            }
            
            if(str[i]<str[currBigIndex])
            {
                smallIndex = i;
                bigIndex = currBigIndex;
            }
        }
        
        if(smallIndex == -1)
            return num;
        
        swap(str[smallIndex],str[bigIndex]);
        
        return stoi(str);
    }
};


