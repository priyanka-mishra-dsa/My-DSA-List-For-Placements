//recursion+memorization
class Solution {
public:
int m,n;
bool solve(int row,int col,vector<vector<int>>& grid, int health,vector<vector<vector<int>>>&dp)
{
    //handle out of bound case
    if(row<0 || row>=m || col<0 || col>=n)
    return false;
    //when i go through a visited path
    if(grid[row][col]==-1)
    return false;
    //unsafe cell
    if(grid[row][col]==1)
    health--;
    //edge case
    if(health<=0)
    return false;
    //base case(reach at the last cell)
    if(row==m-1 && col==n-1)
    return true;
    //
    if(dp[row][col][health]!=-1)
    return dp[row][col][health];
    //currently present at the cell
    int original=grid[row][col];
    grid[row][col]=-1;//mark as visited
    //move in 4 directions
    bool right=solve(row,col+1,grid,health,dp);
    bool left=solve(row,col-1,grid,health,dp);
    bool up=solve(row-1,col,grid,health,dp);
    bool down=solve(row+1,col,grid,health,dp);
    bool ans=right || left || up || down;
    //may be i choose a path which is not correct and i mark as visited
    //now make it unvisited(called backtracking)
    grid[row][col]=original;
    //
    dp[row][col][health]=ans;
    return ans;
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        //make 3d vector
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(health+1,-1)));
        bool ans=solve(0,0,grid,health,dp);
        return ans;    
    }
};
