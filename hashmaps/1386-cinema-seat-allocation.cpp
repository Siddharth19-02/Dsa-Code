class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int j = 0;
        unordered_map<int, unordered_map<int,int> > order;
        for(int i=0;i<reservedSeats.size();i++)
        {
            order[reservedSeats[i][0]][reservedSeats[i][1]]++;
        }
        
        int count =  (n-order.size())*2 ;
        
        for(auto curr: order)
        {
            bool flag = false;
            bool left = false;
            bool right = false;
            
            auto mp = curr.second;
            
            
            if(mp.count(6) and mp.count(5))
            {
                continue;
            }
            
            if(mp.count(6))
            {
                right = true;
            }
            
            if(mp.count(5))
            {
                left = true;
            }
            
            if(!left and mp.count(2)==0 and mp.count(3)==0)
            {
                if(mp.count(4)==0)
                {
                    count++;
                    flag = true;
                }
            }
            
            if(!right and mp.count(8)==0 and mp.count(9)==0)
            {
                if(mp.count(7)==0)
                {
                    count++;
                    flag = true;
                }
            }
            
            if(!flag and !left and !right)
            {
                if(mp.count(4)==0 and mp.count(7)==0)
                {
                    count++;
                }
            }
            
        }
        return count;
    }
};

// good bit manipulation question

// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         int res = 0;
//         unordered_map<int, int> rows;
        
//         for (auto reserved : reservedSeats) {
//             rows[reserved[0]] |= (1 << (reserved[1]-1));
//         }

//         for (auto [row, seats] : rows) {
//             bool a = (~seats & 30) == 30;   //0000011110
//             bool b = (~seats & 120) == 120; //0001111000
//             bool c = (~seats & 480) == 480; //0111100000
            
//             // If we have a or c - sides, we shouldn't consider b - middle
//             res += (a && c) ? 2 : (a || c ) ? 1 : b;
//         }
        
//         // add two for each row with no reserved seats
//         res += 2 * (n - rows.size());
        
//         return res;
//     }
// };
