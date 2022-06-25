class Solution {
public:
    int rm[100001] = {};

    bool valid(string &s, string &p, vector<int> &arr, int k) {

        memset(rm, 0, sizeof(rm));

        for (int i = 0; i < k; ++i) rm[arr[i]] = 1; 

        int n = s.size(), m = p.size(), j = 0; 

        for (int i = 0; i < n && j < m; ++i) {

            if (rm[i] == 1) continue;

            if (s[i] == p[j]) ++j;

        }

        return j == m;

    }

public:

    int maximumRemovals(string s, string p, vector<int>& arr) {

        int left = 0, right = arr.size();

        while (left <= right

) {

            int mid = (left + right) / 2;

            if (valid(s, p, arr, mid)) left = mid+ 1;

            else right= mid - 1;

        }

        return right;
        }
        

};
