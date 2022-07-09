class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int front  = 0;
        int rear = 0;
        int n = gas.size();
        
        
        
        if(n==1)
            return (gas[0]>=cost[0])?0:-1;
        
        int profit = gas[front] - cost[front];
        front++;
        
        while(front!=rear || profit<0)
        {
            
            while(rear!=front and profit<0)
            {
                profit += (cost[rear]-gas[rear]);
                rear = (rear+1)%n;
                
                if(rear==0)
                    return -1;
            }
            
            
            profit += gas[front] - cost[front];
            front=(front+1)%n;
        }
        return rear;
    }
};
