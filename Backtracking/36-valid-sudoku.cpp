class Solution {
public:
    bool issafe(vector<vector<char>>& board,int x,int y,int n,int m,char target)
    {
        int i = 0;
        
        while(i<n)
        {
            if(i!=x and board[i][y]==target)
            {
                return false;
            }
            i++;
        }
        
        int j = 0;
        
        while(j<m)
        {
            if(j!=y and board[x][j]==target)
                return false;
            j++;
        }
        
        i = (x/3)*3;
        j = (y/3)*3;
        
        for(int a = i;a<i+3;a++)
        {
            for(int b = j;b<j+3;b++)
            {
                if(a!= x and b!=y and board[a][b]==target)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board,int x,int y,int n,int m)
    {
        if(x==n)
        {
            return true;
        }
        
        if(y==m)
        {
            if(solve(board,x+1,0,n,m))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(board[x][y]!='.')
        {
            if(issafe(board,x,y,n,m,board[x][y]))
            {
                if(solve(board,x,y+1,n,m))
                    return true;
                else
                    return false;
            }
        }
        else
        {
            if(solve(board,x,y+1,n,m))
                    return true;
                else
                    return false;
        }
        return false;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
    
        return solve(board,0,0,n,m);
        
    }
};
