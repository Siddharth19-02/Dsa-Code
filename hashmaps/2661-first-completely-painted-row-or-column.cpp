class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        unordered_map<int, pair<int,int> >mp;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mp[mat[i][j] ] = {i,j};
            }
        }

        vector<int>countRow(row, 0);
        vector<int>countCol(col,0);

        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> &cood = mp[arr[i] ];
            countRow[cood.first]++;
            countCol[cood.second]++;

            if(countRow[cood.first] == col || countCol[cood.second] == row)
                return i;
        }

        return -1;
    }
};
