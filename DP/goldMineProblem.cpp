//recursion+memorization
class Solution {
  public:
  int M,N;
  int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
  {
      //handle base case
      if(row<0 || row==M || col==N)
      return 0;
      if(dp[row][col]!=-1)
      return dp[row][col];
      //move in 3 directions
      //1.to the cell diagonally up towards the right
      int move1=solve(row-1,col+1,grid,dp);
      //2.move in right cell
      int move2=solve(row,col+1,grid,dp);
      //3.to the cell diagonally down towards the right
      int move3=solve(row+1,col+1,grid,dp);
      int maxPathSum=max({move1,move2,move3});
      int maxGold=grid[row][col]+maxPathSum;
      //store before return
      dp[row][col]=maxGold;
      return maxGold;
  }
    int maxGold(vector<vector<int>>& grid) {
        M=grid.size();
        N=grid[0].size();
        //take 2d dp
        vector<vector<int>>dp(M+1,vector<int>(N+1,-1));
        int maxSum=0;
        //the miner can start from any row in the first column
        for(int row=0;row<M;row++)
        {
            int maxGold=solve(row,0,grid,dp);
            maxSum=max(maxSum,maxGold);
        }
        return maxSum;
    }
};
//Tabulation(Bottom-up)
