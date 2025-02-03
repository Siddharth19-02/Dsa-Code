class Solution {
public:
    bool check(vector<vector<char>>& picture, int x, int y) {
        int n = picture.size();
        int m = picture[0].size();
        
        int count = 0;
        for (int i = 0; i < n; i++) 
        {
            count += (picture[i][y] == 'B');
        }
        
        for (int j = 0; j < m; j++) 
        {
            if (j != y) 
                count += (picture[x][j] == 'B');
        }
        return picture[x][y] == 'B' && count == 1;
    }

    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        int m = picture[0].size();

        int answer = 0;
        for (int j = 0; j < m; j++) 
        {
            answer += check(picture, 0, j);
        }

        for (int i = 1; i < n; i++) 
        {
            answer += check(picture, i, 0);
        }

        for (int j = 0; j < m; j++) 
        {
            picture[0][j] = (picture[0][j] == 'B' ? '1' : '0');
        }
        
        for (int i = 0; i < n; i++) 
        {
            picture[i][0] = (picture[i][0] == 'B' ? '1' : '0');
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(picture[i][j] == 'B')
                {
                    picture[0][j]++;
                    picture[i][0]++;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(picture[i][j] == 'B')
                {
                    if (picture[0][j] == '1' && picture[i][0] == '1')
                    {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
