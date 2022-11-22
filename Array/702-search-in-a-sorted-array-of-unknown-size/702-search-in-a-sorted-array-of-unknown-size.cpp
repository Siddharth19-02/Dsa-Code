/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        
        int increaseIndex = 2;
        
        int startingIndex = 1;
        
        int low = 0;
        
        int high = -1;
        
        while(1)
        {
            if(reader.get(startingIndex)>=target)
            {
                high = startingIndex;
                break;
            }
            startingIndex *= increaseIndex;
        }
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int curr = reader.get(mid);
            
            if(curr == target)
                return mid;
            else if(curr>target)
                high = mid-1;
            else
                low = mid + 1;
        }
        
        return -1;
    }
};
