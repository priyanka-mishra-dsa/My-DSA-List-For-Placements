//recursion+memorization
class Solution {
public:
int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
{
    //base case
    if(i==m-1 && j==n-1)
    return 1;
    if(i<0 || i>=m || j<0 || j>=n)//out of bound cond
    return 0;
    //extra
    if(dp[i][j]!=-1)
    return dp[i][j];
    //2 ways to move
    int right=solve(i,j+1,m,n,dp);
    int down=solve(i+1,j,m,n,dp);
    int count=right+down;
    //store before return
    dp[i][j]=count;
    return count;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       int ans=solve(0,0,m,n,dp);
       return ans;   
    }
};
//Tabulation
class Solution {
public:
int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
{
    //base case
    if(i==m-1 && j==n-1)
    return 1;
    if(i<0 || i>=m || j<0 || j>=n)//out of bound cond
    return 0;
    //extra
    if(dp[i][j]!=-1)
    return dp[i][j];
    //2 ways to move
    int right=solve(i,j+1,m,n,dp);
    int down=solve(i+1,j,m,n,dp);
    int count=right+down;
    //store before return
    dp[i][j]=count;
    return count;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                //handle base case
                if(i==m-1 && j==n-1)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int right=0,down=0;
                    if(j+1<n)
                    {
                        right=dp[i][j+1];
                    }
                    if(i+1<m)
                    {
                        down=dp[i+1][j];
                    }
                    int countWay=right+down;
                    //store ways value in current cell you are!
                    dp[i][j]=countWay;
                }
            }
        }
        return dp[0][0];
    }
};
