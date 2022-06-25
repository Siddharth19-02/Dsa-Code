class Solution {
public:
    bool canReachInTime(const vector<int>& dist, const double hour, int speed)
    {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
            time += ((dist[i] + speed - 1) / speed);
        
        time += ((double)dist.back()) / speed;
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        if (hour <= (double)(n- 1))
            return -1;
        
        int low = 1, high = 1e7, mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (canReachInTime(dist, hour, mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        return high;
        
    }
};
