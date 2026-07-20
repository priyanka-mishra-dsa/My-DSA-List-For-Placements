//recursion+memorization
class Solution {
public:
int m,n;
int Row[4]={0,0,-1,1};
int Col[4]={-1,1,0,0};
const int MOD=1e9+7;
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //no base case required
    //dp check
    if(dp[row][col]!=-1)
    return dp[row][col];
    //one single cell is also considered as a path
    long long path=1;
    for(int k=0;k<4;k++)
    {
        int nextRow=row+Row[k];
        int nextCol=col+Col[k];
        //before move check next row,col value is greater or not
        if(nextRow<m && nextRow>=0&& nextCol<n && nextCol>=0 &&grid[nextRow][nextCol]>grid[row][col])
        {
            path=(path+solve(nextRow,nextCol,grid,dp))%MOD;
        }
    }
    dp[row][col]=path;
    return path;
}
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        long long totalPaths=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                totalPaths=(totalPaths+solve(row,col,grid,dp))%MOD;
            }
        }
        return totalPaths;
    }
};
