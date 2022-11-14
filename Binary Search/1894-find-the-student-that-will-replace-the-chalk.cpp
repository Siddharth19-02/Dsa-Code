class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long int sum = chalk[0];
        int high = chalk.size()-1;
        int temp = k-chalk[0];
        
        if(temp<0)
            return 0;
        
        for(int i=1;i<chalk.size();i++)
        {
            sum += chalk[i];
            temp -= chalk[i];
            if(temp<0)
                return i;
            chalk[i] += chalk[i-1];
        }
        
        k = k%sum;
        
        if(k==0)
            return 0;
        
        int low = 0;
        
        
        int ans = 0;
        
        while(low<=high)
        {
            cout<<low<<" "<<high<<endl;
            int mid = low + (high-low)/2;
            
            if(chalk[mid]<=k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
