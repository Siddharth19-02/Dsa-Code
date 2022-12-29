class Solution {
public:
    static bool compare(vector<int>&a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
                return a[2]<b[2];
            else
                return a[1]<b[1];
        }
        else
        {
            return a[0]<b[0];
        }
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();

        vector<int>result;

        vector<vector<int> >vec(n);

        for(int i=0;i<n;i++)
        {
            vec[i].push_back(tasks[i][0]);
            vec[i].push_back(tasks[i][1]);
            vec[i].push_back(i);
        }
        sort(vec.begin(),vec.end(),compare);

        priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > >pq;
        long long int time = vec[0][0];
        pq.push({vec[0][1],vec[0][2]});
        int i=1;

        while(!pq.empty())
        {
            pair<int,int> curr = pq.top();
            pq.pop();
            time += curr.first;
            result.push_back(curr.second);

            while(i<n and vec[i][0]<=time)
            {
                pq.push({vec[i][1],vec[i][2]});
                i++;
            }

            if(i<n and pq.empty())
            {
                pq.push({vec[i][1],vec[i][2]});
                time = vec[i][0];
                i++;
            }
        }

        return result;
    }
};
