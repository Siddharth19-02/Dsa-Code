class SparseVector {
    vector< pair<int,int> >nums1;
public:
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                nums1.push_back({i,nums[i]});
            }
        }
    }

    vector<pair<int,int> > getVector()
    {
        return nums1;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        const vector< pair<int,int> > &nums2 = vec.getVector();

        int n = nums1.size();
        int m = nums2.size();

        int i=0, j=0, ans = 0;

        while(i<n and j<m)
        {
            if(nums1[i].first == nums2[j].first)
            {
                ans += nums1[i].second * nums2[j].second;
                i++;
                j++;
            }
            else if(nums1[i].first < nums2[j].first)
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
