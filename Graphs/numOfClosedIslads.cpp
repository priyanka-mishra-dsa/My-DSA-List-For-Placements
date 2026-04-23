class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;
}
void bfs(vector<vector<int>>& grid,int r,int c)
{
    queue<pair<int,int>>q;
    q.push({r,c});
    //mark as visited
    grid[r][c]=1;
    while(!q.empty())
    {
        int Row=q.front().first;
        int Col=q.front().second;
        q.pop();
        //check for neig land and mark as 1
        for(int k=0;k<4;k++)
        {
            int r1=Row+row[k];
            int c1=Col+col[k];
            if(valid(r1,c1)&&grid[r1][c1]==0)
            {
                q.push({r1,c1});
                grid[r1][c1]=1;
            }
        }
    }
}
    int closedIsland(vector<vector<int>>& grid) {
        //0s->land
        //1s->water
        //closed islands means->land(0s)which is closed by water(1s) in all direction
        //if land touchs boundary do not consider
        //if wates(1s)touch boundary ->no problem,valid
        //using boundary traversal 
        r=grid.size();
        c=grid[0].size();
        //remove all the land(0s)which is connected with boundary
        //why we use bfs as a function here?
        //ans:for land boundary removal connected neig 0s ko 1 bna padega
        for(int i=0;i<r;i++)
        {
            if(grid[i][0]==0)
            {
                //may be this land is the part of  island which is connected to the bondary
                //for close island convertt 0s into 1s(water)
                //island connected with lands in 4 directions
                //convert them in 1s
                //instead of writing bfs code here use bfs function for resusability
                bfs(grid,i,0);
            }
            if(grid[i][c-1]==0)
            {
               bfs(grid,i,c-1);
            }

        }
        for(int i=0;i<c;i++)
        {
            if(grid[0][i]==0)
            {
                bfs(grid,0,i);
            }
            if(grid[r-1][i]==0)
            {
               bfs(grid,r-1,i);
            }
        }
        //after removal remaining 0s will be the no of closed islands
        int closedIsland=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                {
                    //call bfs(it will make all os in 1s)
                    bfs(grid,i,j);
                    closedIsland++;
                }
            }
        }
        return closedIsland;   
    }
};
