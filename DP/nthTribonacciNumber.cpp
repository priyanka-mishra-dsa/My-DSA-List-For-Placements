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
//Using Tabulation(Bottom-up method)
class Solution {
public:
int solveUsingTabul(int n)
{
    vector<int>dp(n+1,-1);
    //base cases 
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
    int res1=dp[i-1];
    int res2=dp[i-2];
    int res3=dp[i-3];
    int sum=res1+res2+res3;
    //store that value
    dp[i]=sum;
    }
    return dp[n];
}
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=solveUsingTabul(n);
        return ans;   
    }
};
