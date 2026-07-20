//recursion+memorization
class Solution {
public:
int m,n;
int Row[4]={0,0,-1,1};
int Col[4]={-1,1,0,0};
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    //dp
    if(dp[row][col]!=-1)
    return dp[row][col];
    //move in 4 directions
    int maxL=1;
    for(int k=0;k<4;k++)
    {
        int nextRow=row+Row[k];
        int nextCol=col+Col[k];
        //before move check next row,col value is greater or not
        if(nextRow<m && nextRow>=0&& nextCol<n && nextCol>=0 &&grid[nextRow][nextCol]>grid[row][col])
        {
            int ans=1+solve(nextRow,nextCol,grid,dp);
            //4 moves me jo max hoga usko store krenge dp me
             maxL=max(ans,maxL);
        }
    }
    dp[row][col]=maxL;
    return maxL;
}
    int longestIncreasingPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int maxLen=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                int ans=solve(row,col,grid,dp);//largest path for each cell
                //largest path amoung all the cell
                maxLen=max(ans,maxLen);
            }
        }
        return maxLen;
    }
};
//Tabulation is not possible in this case

