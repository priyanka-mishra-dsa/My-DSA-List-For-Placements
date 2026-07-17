//recursion+memorization
class Solution {
public:
static const int MOD=1e9+7;
int solve(int m,int n,int maxMove,int row,int col,vector<vector<vector<int>>>&dp)
{
    //base case 
    if(row<0 || row>=m || col<0 || col>=n)
    return 1;
    if(maxMove==0)
    return 0;
    if(dp[row][col][maxMove]!=-1)
    return dp[row][col][maxMove];
    //4 direction
    long long top=solve(m,n,maxMove-1,row-1,col,dp);
    long long down=solve(m,n,maxMove-1,row+1,col,dp);
    long long left=solve(m,n,maxMove-1,row,col-1,dp);
    long long right=solve(m,n,maxMove-1,row,col+1,dp);
    long long totalPaths=(top+down+left+right)%MOD;
    dp[row][col][maxMove]=totalPaths;
    return totalPaths;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //3 states are changing everytime
        //row,col,maxMoves
        //use 3d dp
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        int ans=solve(m,n,maxMove,startRow,startColumn,dp);
        return ans;    
    }
};
