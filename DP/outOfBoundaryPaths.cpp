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
//Tabulation
class Solution {
public:
static const int MOD=1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //3 states are changing everytime
        //row,col,maxMoves
        //use 3d dp
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,0)));
        //base case if(maxMove==0) return 0->already intialized main jab vector 0 se fill kiya
        for(int i=1;i<=maxMove;i++)
        {
            for(int row=0;row<m;row++)
            {
                for(int col=0;col<n;col++)
                {
                    long long top,down,left,right;
                    //handle for top
                    if(row==0)
                    top=1;
                    else
                    top=dp[row-1][col][i-1];
                    //handle for down
                    if(row==m-1)
                    down=1;
                    else
                    down=dp[row+1][col][i-1];
                    //handle left
                    if(col==0)
                    left=1;
                    else
                    left=dp[row][col-1][i-1];
                    //handle right
                    if(col==n-1)
                    right=1;
                    else
                    right=dp[row][col+1][i-1];
                    int totalPaths=(top+down+left+right)%MOD;
                    dp[row][col][i]=totalPaths;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};
