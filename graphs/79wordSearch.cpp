class Solution {
public:
    bool searchnext(vector<vector<char>> board,const char* word,int si,int ei,int m,int n)
    {

        if(si<0||si>=m||ei<0||ei>=n||board[si][ei]=='*'||*word!=board[si][ei])
        return false;

        if(*(word+1)=='\0')
            return true;

        char now = board[si][ei];
        board[si][ei]='*';

        bool a=searchnext(board,word+1,si-1,ei,m,n);
            if(a)
            {
                return true;
            }
        bool b=searchnext(board,word+1,si+1,ei,m,n);
            if(b)
                return true;
        bool c=searchnext(board,word+1,si,ei-1,m,n);
            if(c)
                return true;
        bool d=searchnext(board,word+1,si,ei+1,m,n);
            if(d)
                return true;

        board[si][ei]=now;

        return false;
    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(searchnext(board,word.c_str(),i,j,n,m))
                    return true;
            }
        }
        return false;
    }
};
