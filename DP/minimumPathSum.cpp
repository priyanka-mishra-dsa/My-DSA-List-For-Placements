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
//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int MinPathSum=0;
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                //handle base case
                if(i==row-1 && j==col-1)
                {
                    dp[i][j]=grid[i][j];
                }
                //
                if(i==row-1)
                {
                    //only go in right
                    if(j+1<col)
                    dp[i][j]=grid[i][j]+dp[i][j+1];
                }
                else if(j==col-1)
                {
                    //only go down
                    if(i+1<row)
                    dp[i][j]=grid[i][j]+dp[i+1][j];
                }
                else
                {
                    // i can go on right or down both
                    MinPathSum=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                    //store the value
                    dp[i][j]=MinPathSum;
                }
            }
        }
        return dp[0][0];
    }
};
