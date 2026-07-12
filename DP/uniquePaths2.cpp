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
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        //take 2d dp
        vector<vector<long long>>dp(row,vector<long long>(col,0));
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                //handle obstacle
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                 //handle base case
                else if(i==row-1 && j==col-1)
                {
                    dp[i][j]= 1;
                }
                else
                {
                    long long right=0,down=0;
                    if(j+1<col)
                    {
                        right=dp[i][j+1];
                    }
                    if(i+1<row)
                    {
                        down=dp[i+1][j];
                    }
                    long long countPaths=right+down;
                    dp[i][j]=countPaths;
                }
            }
        }
        return dp[0][0];
    }
};
