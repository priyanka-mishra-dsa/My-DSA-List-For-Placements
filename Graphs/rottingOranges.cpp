class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}
    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        bool hasFresh=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
                //handle edge case grid =[[0]]
                else if(grid[i][j]==1)
                {
                    hasFresh=1;
                }
            }
        }
        if(hasFresh==0)
        return 0;
        
        int timer=0;
        while(!q.empty())
        {
            timer++;
            int current=q.size();
            while(current--)
            {
                int Row=q.front().first;
                int Col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    if(valid(Row+row[k],Col+col[k])&&grid[Row+row[k]][Col+col[k]]==1)
                    {
                        grid[Row+row[k]][Col+col[k]]=2;
                        q.push(make_pair(Row+row[k],Col+col[k]));
                    }
                }

            }
        }
          for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return timer-1;
    }
};
