class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        
        int count =0; 
        
        for(auto i: hash){
            if(k==0) {
                if(i.second>1) 
                    count++;
            }
            
             else {
                 if (hash.find(i.first - k) != hash.end()) 
                     count++;
             }
        }
        
        return count;
        
    }
};

// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         if(nums.size()<=1) return 0;
//         vector<pair<int,int>> v;
//         int i=0,j=1;
        
//         for(;(i<nums.size()) && (j<nums.size());){
//             if(i==j){
//                 j++;
//             }
//             else if(nums[j]-nums[i]==k){
//                 v.push_back({nums[i],nums[j]});
//                 i++;
//             }
//             else if(nums[j]-nums[i]>k){
//                 i++;
//             }
//             else{
//                 j++;
//             }
//         }
        
//         if(v.size()<=1) return v.size();
//         int answer=1;
//         for(auto it=v.begin()+1;it!=v.end();it++){
//             if(*it!=*(it-1)) answer++;
//         }
//         return answer;
//     }
// };
