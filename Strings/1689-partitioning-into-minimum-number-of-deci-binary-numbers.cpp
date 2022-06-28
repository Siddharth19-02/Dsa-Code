class Solution {
public:
    int minPartitions(string n) {
        char maxi = n[0];
        for(auto x : n)
            maxi = max(maxi,x);
        return int(maxi-'0');
    }
};
