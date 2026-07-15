//recursion+memorization
class Solution {
public:
int M,N;
int solve(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp)
{
    //handle out of bound case
    if(col<0 ||col>=N)
    return 1e9;
    //handle base case
    if(row==M-1)
    return matrix[row][col];
    if(dp[row][col]!=INT_MAX)
    return dp[row][col];
    //movement
    int move1=solve(row+1,col-1,matrix,dp);
    int move2=solve(row+1,col,matrix,dp);
    int move3=solve(row+1,col+1,matrix,dp);
    int minPathSum=min({move1,move2,move3});
    int minFallPathSum=INT_MAX;
    minFallPathSum=matrix[row][col]+minPathSum;
    dp[row][col]=minFallPathSum;
    return minFallPathSum;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        M=matrix.size();
        N=matrix[0].size();
        vector<vector<int>>dp(M,vector<int>(N,INT_MAX));
        int minFallPathSum=INT_MAX;
        for(int col=0;col<N;col++)
        {
            int FallPathSum=solve(0,col,matrix,dp);
             minFallPathSum=min(FallPathSum,minFallPathSum);
        }
        return minFallPathSum;
    }
};
//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int M=matrix.size();
        int N=matrix[0].size();
        vector<vector<int>>dp(M+1,vector<int>(N,INT_MAX));
        //base case
        //dp[M-1][col]=matrix[row][col](col only changes)
        for(int col=0;col<N;col++)
        {
           dp[M-1][col]=matrix[M-1][col];
        }
        for(int row=M-2;row>=0;row--)
        {
            for(int col=0;col<N;col++)
            {
                int move1=INT_MAX;
                if(col>0)
                move1=dp[row+1][col-1];
                int move2=dp[row+1][col];
                int move3=INT_MAX;
                if(col<N-1)
                move3=dp[row+1][col+1];
                int minPathSum=min({move1,move2,move3});
                int minFallPathSum=matrix[row][col]+minPathSum;
                dp[row][col]=minFallPathSum;
            }
        }
        int ans=INT_MAX;
        for(int col=0;col<N;col++)
        {
            ans=min(ans,dp[0][col]);
        }
        return ans;
    }
};
