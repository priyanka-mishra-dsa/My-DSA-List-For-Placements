class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}
    int numEnclaves(vector<vector<int>>& grid) {
        //count how many cells are present inside the gride
        //when cell traverse in 4 directions it will never go out of boundary
        //use boundary traversal
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        //do boundary traversal and boundary pr jitne land usko push into the queue
        //r==0,r==r-1,c==0,c==c-1
        for(int i=0;i<r;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                //make as visited
                grid[i][0]=0;
            }
            if(grid[i][c-1]==1)
            {
                q.push({i,c-1});
                //mark as visited
                grid[i][c-1]=0;
            }
        }
        for(int i=0;i<c;i++)
        {
           if(grid[0][i]==1)
           {
            q.push({0,i});
            grid[0][i]=0;
           }
           if(grid[r-1][i]==1)
           {
            q.push({r-1,i});
            grid[r-1][i]=0;
           }
        }
        while(!q.empty())
        {
            int Row=q.front().first;
            int Col=q.front().second;
            q.pop();
            //visit neig in 4 directions
            for(int k=0;k<4;k++)
            {
                int r1=Row+row[k];
                int c1=Col+col[k];
                if(valid(r1,c1)&&grid[r1][c1]==1)
                {
                    q.push({r1,c1});
                    grid[r1][c1]=0;
                }
            }
        }
        //count land who cannont cross the boundary
        int land=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    land++;
                }
            }
        }
        return land;
    }
};
