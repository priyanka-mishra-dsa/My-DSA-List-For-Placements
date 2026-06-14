//using memorization
class Solution {
public:
int solveUsingMemo(vector<int>&dp,int n)
{
    if(n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    //extra thing
    if(dp[n]!=-1)
    return dp[n];
    int res1=solveUsingMemo(dp,n-1);
    int res2=solveUsingMemo(dp,n-2);
    int res3=solveUsingMemo(dp,n-3);
    int sum=res1+res2+res3;
    //store that value
    dp[n]=sum;
    return sum;
}
int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveUsingMemo(dp,n);
        return ans;   
    }
};
