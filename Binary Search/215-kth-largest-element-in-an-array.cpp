class Solution {
public:
    
    int kthsmallest(vector<int>& arr, int l, int r, int k) {
       
       
       //int pivot = r;
       int start = l;
       
       int i = l;
       
       while(i<r)
       {
           if(arr[i]<=arr[r])
           {
               swap(arr[i],arr[start]);
               start++;
           }
           i++;
       }
       
       swap(arr[start],arr[r]);
       
       if(start == k)
       {
           return arr[start];
       }
       
       
       
       if(k<start)
            return kthsmallest(arr,l,start-1,k);
        else
            return kthsmallest(arr,start+1,r,k);
       
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        
        return kthsmallest(nums,0,n-1,n-k);
    }
};
