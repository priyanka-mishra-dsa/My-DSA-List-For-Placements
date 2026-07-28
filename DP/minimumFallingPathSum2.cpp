//recursion+memorization
class Solution {
public:
int n;
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //find current cell value
    int current=grid[row][col];
    //base case(reached at last row)
    if(row==n-1)
    return grid[row][col];
    //and now go to the next row
    //in next row we have also multiple options
    //
    if(dp[row][col]!=INT_MAX)
    return dp[row][col];
    int minSum=INT_MAX,ans=INT_MAX;
    for(int nextCol=0;nextCol<n;nextCol++)
    {
        //prev and next row col should not be same
        if(nextCol!=col)
        {
            ans=current+solve(row+1,nextCol,grid,dp);
            minSum=min(ans,minSum);
        }
    }
    dp[row][col]=minSum;
    return minSum;
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        //each time row as well as col is changing
        //take 2d dp
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        //start from first row
        int minSum=INT_MAX,ans=INT_MAX;
        for(int col=0;col<n;col++)
        {
            ans=solve(0,col,grid,dp);
            minSum=min(ans,minSum);
        }
        return minSum;    
    }
};
