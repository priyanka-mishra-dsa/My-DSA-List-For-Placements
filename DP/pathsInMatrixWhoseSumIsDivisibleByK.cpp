//recursion+memorization
class Solution {
public:
int m,n;
int MOD=1e9+7;
int solve(int row,int col,int rem,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>&dp)
{
    //handle out of bound
    if(row<0 || row>=m || col<0 || col>=n)
    return 0;
    //update remainder
    rem=(rem+grid[row][col])%k;
    //base case
    if(row==m-1 && col==n-1)
    {
        if(rem==0)
        return 1;
        else
        return 0;
    }
    //dp check
    if(dp[row][col][rem]!=-1)
    return dp[row][col][rem];
    //move in 2 directions
    int right=solve(row,col+1,rem,grid,k,dp);
    int down=solve(row+1,col,rem,grid,k,dp);
    int totalPaths=(right+down)%MOD;
    //store first
    dp[row][col][rem]=totalPaths;
    return totalPaths;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        //each move me row,col,rem states are changing
        //i can take 3d dp
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        //why i take k in vector in place of rem
        //becaue rem = sum % k doing that
        //k=3,rem=0,1,2  rem<k
        //rem=[0-k-1]
        //k ==rem (in terms of state)
        int ans=solve(0,0,0,grid,k,dp);
        return ans;       
    }
};
//Tabulation
