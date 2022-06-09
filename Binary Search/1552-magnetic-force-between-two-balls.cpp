class Solution {
    int result(vector<int>& position, int dist) {
        int ans = 1, curr = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - curr >= dist) {
                ans++;
                curr = position[i];
            }
        }
        return ans;
    }
public:
   int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0, high = position[position.size()-1] - position[0];
        while (low < high) {
            int mid = high- (high - low) / 2;
            if (result(position, mid) >= m)
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};
