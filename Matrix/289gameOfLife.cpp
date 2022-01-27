class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m  = board[0].size();
        
        vector<vector<int> >vec(n,vector<int>(m));
        
        if(n<=1 or m<=1)
        {
            board = vec;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = 0;
                if(i==0 and j==0)
                {
                    sum += board[i][j+1] +board[i+1][j] + board[i+1][j+1];
                }
                else if(i==0 and j==m-1)
                {
                    sum += board[i][j-1] +board[i+1][j-1] + board[i+1][j];
                }
                else if(i==n-1 and j==0)
                {
                    sum += board[i-1][j] +board[i][j+1] + board[i-1][j+1];
                }
                else if(i==n-1 and j==m-1)
                {
                    sum += board[i][j-1] +board[i-1][j] + board[i-1][j-1];
                }
                else if(i==0)
                {
                    sum += board[i][j+1] +board[i+1][j] + board[i+1][j+1] + board[i][j-1] + board[i+1][j-1];
                }
                else if(i==n-1)
                {
                    sum +=  board[i-1][j] +board[i][j+1] + board[i-1][j+1]+board[i][j-1] + board[i-1][j-1];
                }
                else if(j==0)
                {
                    sum += board[i-1][j] +board[i][j+1] + board[i-1][j+1] + board[i+1][j] + board[i+1][j+1];
                }
                else if(j==m-1)
                {
                    sum += board[i][j-1] +board[i-1][j] + board[i-1][j-1] + board[i+1][j]+ board[i+1][j-1];
                }
                else 
                {
                    sum += board[i][j-1]+ board[i][j+1]+ board[i+1][j]+board[i-1][j] +board[i+1][j+1]+board[i-1][j-1]+board[i+1][j-1]+board[i-1][j+1];
                }
                
                if(sum<2 or sum>3)
                {
                    vec[i][j] = 0;
                }
                else if(sum==3)
                {
                    vec[i][j] = 1;
                }
                else if(sum>=2 and sum<=3)
                {
                    vec[i][j] = board[i][j];
                }
                
            }
        }
        board = vec;
        return;
    }
};
