class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}
    int islandPerimeter(vector<vector<int>>& grid) {
        //only one island is present
        //perimeter=count bondaries of island
        r=grid.size();
        c=grid[0].size();
        //do no take queue here
        int perimeter=0;
        //traverse in whole grid
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    int sides=4;
                    //go in 4 directions to check adjacent land
                    for(int k=0;k<4;k++)
                    {
                        int Row=i+row[k];
                        int Col=j+col[k];
                        if(valid(Row,Col)&&grid[Row][Col]==1)
                        {
                            //remove common side because it is not the part of boundary;
                            sides--;
                        }

                    }
                    perimeter=perimeter+sides;
                }
            }
        }
        return perimeter;      
    }
};
