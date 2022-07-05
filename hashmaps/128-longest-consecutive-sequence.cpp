class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
      int n = arr.size();
       unordered_set<int>s(arr.begin(),arr.end());
      int total=0;
      for(int i=0;i<n;i++)
      {
          int count=0;
          if(s.find(arr[i]-1)==s.end())
          {
              count++;
              while(s.find(arr[i]+count)!=s.end())
              {
                  count++;
              }
          }
          if(count>total)
          total=count;
      }
      return total;
        
    }
};
