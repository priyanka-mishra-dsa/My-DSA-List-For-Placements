class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};//when only horizontal,vertical 
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
   return i>=0&&i<r&&j>=0&&j<c;
}
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        //visit entire cell of grid and push all the lands in the queue
        int countIslands=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                //count connected land as only 1 islands
                //Some '1's are connected → same island
                //We should count groups, not individual cells
                if(grid[i][j]=='1')
                {
                    countIslands++;
                    q.push({i,j});
                    grid[i][j]='0';
                }
                while(!q.empty())
                {
                    int Row=q.front().first;
                    int Col=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int r1=Row+row[k];
                        int c1=Col+col[k];
                        if(valid(r1,c1)&& grid[r1][c1]=='1')
                        {
                            grid[r1][c1]='0';
                            q.push({r1,c1});
                        }
                    }
                }

            }
        }
       return countIslands;
        
    }
};
