//recursion+memorization
class Solution {
public:
int solve(int i, int j,int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
{
    //Base case
    if(i<0 || i>=row ||j<0 ||j>=col)
    return 0;
    if(obstacleGrid[i][j]==1)
    return 0;
    if(i==row-1 && j==col-1)
    return 1;
    //extra for dp
    if(dp[i][j]!=-1)
    return dp[i][j];
    //at each cell we have to options to move
    int right=solve(i,j+1,row,col,obstacleGrid,dp);
    int down=solve(i+1,j,row,col,obstacleGrid,dp);
    int countPath=right+down;
    //store the value before returning
    dp[i][j]=countPath;
    return countPath;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        //take 2d dp
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        int ans=solve(0,0,row,col,obstacleGrid,dp);
        return ans;    
    }
};
//Tabulation
