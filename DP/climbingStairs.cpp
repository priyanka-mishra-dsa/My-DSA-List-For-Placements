//Using recursion->give TLE
class Solution {
public:
int countWays(int n)
{
    //base case
    if(n==0) return 1;
    if(n==1) return 1;
    int jump1stepDown=countWays(n-1);
    int jump2stepDown=countWays(n-2);
    int ways=jump1stepDown+jump2stepDown;
    return ways;
}
    int climbStairs(int n) {
       int ans=countWays(n);
       return ans;
    }
};
//Using memorization Dp
class Solution {
public:
int countWays(vector<int>&dp,int n)
{
    //base case
    if(n==0) return 1;
    if(n==1) return 1;
    //check
    if(dp[n]!=-1)
    return dp[n];
    int jump1stepDown=countWays(dp,n-1);
    int jump2stepDown=countWays(dp,n-2);
    int ways=jump1stepDown+jump2stepDown;
    //store the result in dp
    dp[n]=ways;
    return ways;
}
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       int ans=countWays(dp,n);
       return ans;
    }
};
