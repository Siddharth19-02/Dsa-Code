class Solution {
public:
    bool totalPiecesRecieved(vector<int>& ribbons, int cut, int k)
    {
        long long int totalCuts = 0;
        for(int i=0;i<ribbons.size();i++)
        {
            totalCuts += (ribbons[i]/cut);
        }

        return (totalCuts>=k);
    }

    int maxLength(vector<int>& ribbons, int k) {
        int maxi = INT_MIN;

        for(int i=0;i<ribbons.size();i++)
        {
            maxi = max(maxi, ribbons[i]);
        }

        int low = 1;
        int high = maxi;
        int ans = 0;

        while(low<=high)
        {
            int mid = (low + high)/2;

            bool result = totalPiecesRecieved(ribbons, mid, k);

            if(result)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }

            cout<<low<<" "<<high<<endl;
        }

        return ans;
    }
};
