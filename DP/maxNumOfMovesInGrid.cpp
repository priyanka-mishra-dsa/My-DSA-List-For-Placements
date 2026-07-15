//recursion+memorization
class Solution {
public:
int M,N;
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //handle out of bound case
    if(row<0 ||row>M-1)
    return 0;
    //handle base case
    if(col==N-1)
    return 0;
    if(dp[row][col]!=-1)
    return dp[row][col];
    //handle 3 moves
    //move1
    int move1=0;
    if(row>0 &&grid[row-1][col+1]>grid[row][col])
    {
        move1=1+solve(row-1,col+1,grid,dp);
    }
    int move2=0;
    if(grid[row][col+1]>grid[row][col])
    {
        move2=1+solve(row,col+1,grid,dp);
    }
    int move3=0;
    if(row<M-1 &&grid[row+1][col+1]>grid[row][col])
    {
        move3=1+solve(row+1,col+1,grid,dp);
    }
    int maxMoves=max({move1,move2,move3});
    dp[row][col]=maxMoves;
    return maxMoves;
}
    int maxMoves(vector<vector<int>>& grid) {
        M=grid.size();
        N=grid[0].size();
        vector<vector<int>>dp(M,vector<int>(N,-1));
        int maxMoves=0;
        for(int row=0;row<M;row++)
        {
            maxMoves=max(maxMoves,solve(row,0,grid,dp));
        }
        return maxMoves;    
    }
};
//Tabulation
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M=grid.size();
        int N=grid[0].size();
        vector<vector<int>>dp(M,vector<int>(N+1,0));
        //base case
        //dp[row][N-1]=0(handle when intialize dp by 0)
        for(int col=N-2;col>=0;col--)
        {
           for(int row=0;row<M;row++)
           {
              int move1=0,move2=0,move3=0;
              if(row>0 &&grid[row-1][col+1]>grid[row][col])
              {
                move1=1+dp[row-1][col+1];
              }
              if(grid[row][col+1]>grid[row][col])
              {
                move2=1+dp[row][col+1];
              }
              if(row<M-1 &&grid[row+1][col+1]>grid[row][col])
              {
                move3=1+dp[row+1][col+1];
              }
              int maxMoves=max({move1,move2,move3});
              dp[row][col]=maxMoves;
           }
        }
        int ans=0;
        for(int row=0;row<M;row++)
        {
            ans=max(ans,dp[row][0]);
        }
        return ans;
    }
};
