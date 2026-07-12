//recursion+memorization
class Solution {
public:
int solve(int i,int j,int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //base case
    if(i==row-1 && j==col-1)
    return grid[i][j];
    //extra 
    if(dp[i][j]!=-1)
    return dp[i][j];
    int MinPathSum=0;
    if(j==col-1)
    {
        //i cannot move right 
        //i can only move in down
        return grid[i][j]+solve(i+1,j,row,col,grid,dp);
    }
    else if(i==row-1)
    {
        //i cannot move in down
        //i will move only in right
        return grid[i][j]+solve(i,j+1,row,col,grid,dp);
    }
    else
    {
        //add current cell value+call for next cell
         MinPathSum=grid[i][j]+min(solve(i,j+1,row,col,grid,dp),solve(i+1,j,row,col,grid,dp));
        //store
        dp[i][j]=MinPathSum;
    }
    return MinPathSum;
}
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        int ans=solve(0,0,row,col,grid,dp);
        return ans;   
    }
};
