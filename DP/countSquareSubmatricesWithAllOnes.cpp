//recursion+memorization
class Solution {
public:
int m,n;
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //handle out of bound condition
    if(row <0 || row>=m || col<0 || col>=n)
    return 0;
    //base case
    if(grid[row][col]==0)
    return 0;
    //handle dp 
    if(dp[row][col]!=-1)
    return dp[row][col];
    //we have 3 options to move
    int right=solve(row,col+1,grid,dp);
    int down=solve(row+1,col,grid,dp);
    int diagonal=solve(row+1,col+1,grid,dp);
    int totalSquareSubmatrix=1+min({right,down,diagonal});
    //store
    dp[row][col]=totalSquareSubmatrix;
    return totalSquareSubmatrix;
}
    int countSquares(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //2d dp->row,col states are always changing
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=solve(0,0,grid,dp);(in this case i am only checking for first cell)
        //check for all cells
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              ans=ans+solve(i,j,grid,dp);
            }
        }
        return ans;        
    }
};
//Tabulation
