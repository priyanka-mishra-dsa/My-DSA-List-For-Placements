//rec+memo
class Solution {
public:
const int MOD=1e9+7;
int solve(int n,int num,int x,vector<vector<int>>&dp)
{
    //base case
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    //calulate power first
    int currPowerValue=pow(num,x);
    if(currPowerValue>n)
    {
        return 0;
    }
     if(dp[n][num]!=-1)
    return dp[n][num];
    int takeCurrNo=solve(n-currPowerValue,num+1,x,dp);
    int skipCurrNo=solve(n,num+1,x,dp);
    int count=(takeCurrNo+skipCurrNo)%MOD;
    dp[n][num]=count;
    return count;
}
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(n,1,x,dp);
        return ans;    
    }
};
