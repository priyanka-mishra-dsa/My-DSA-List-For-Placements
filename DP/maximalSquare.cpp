//recursion+memorization
class Solution {
public:
int m,n;
int solve(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&dp)
{
    //handle out of bound case
    if(row<0 || row>=m || col<0 || col>=n)
    return 0;
    //handle base case
    if(grid[row][col]=='0')
    return 0;
    //
    if(dp[row][col]!=-1)
    return dp[row][col];
    //
    int right=solve(row,col+1,grid,dp);
    int down=solve(row+1,col,grid,dp);
    int diagonal=solve(row+1,col+1,grid,dp);
    int total=1+min({right,down,diagonal});
    dp[row][col]=total;
    return total;
}
    int maximalSquare(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //find largest square
        int maxSq=0,ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=solve(i,j,grid,dp);
                maxSq=max(maxSq,ans);
            }
        }
        //return area
        int area=maxSq*maxSq;
        return area;   
    }
};
//Tabulation
class Solution {
public:
int m,n;
    int maximalSquare(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int maxSq=0;
        for(int row=m-1;row>=0;row--)
        {
            for(int col=n-1;col>=0;col--)
            {
               if(grid[row][col]=='0')
               {
                  dp[row][col]=0;
               }
               else if(grid[row][col]=='1')
               {
                  int right=dp[row][col+1];
                  int down=dp[row+1][col];
                  int diagonal=dp[row+1][col+1];
                  int ans=1+min({right,down,diagonal});
                  dp[row][col]=ans;
                  //find largest square
                  maxSq=max(maxSq,ans);
               }
            }
        }
        int area=maxSq*maxSq;
        return area;     
    }
};
