//recursion+memorization
class Solution {
public:
int solve(int n,vector<int>&dp)
{
    //base case
    if(n==0)
    return 0;
    //extra
    if(dp[n]!=-1)
    return dp[n];
    int minCount=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        int ans=solve(n-i*i,dp)+1;
        minCount=min(minCount,ans);
    }
    //store before returning
    dp[n]=minCount;
    return minCount;
}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        int ans=solve(n,dp);
        return ans;    
    }
};
//Tabulation
