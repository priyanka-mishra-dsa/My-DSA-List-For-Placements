class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        int maxArea=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    //1 land mil gya
                    int area=0;
                    q.push({i,j});
                    //mark as visited
                    grid[i][j]=0;
                    while(!q.empty())
                    {
                        area++;
                        int Row=q.front().first;
                        int Col=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int r=Row+row[k];
                            int c=Col+col[k];
                            if(valid(r,c)&&grid[r][c]==1)
                            {
                                grid[r][c]=0;
                                q.push({r,c});
                            }
                        }
                    }
                    maxArea=max(area,maxArea);

                }
            }
        }
        return maxArea;
        
    }
};
