//Method 1:using recursion
class Solution {
public:
int recursion(int n)
{
    //base case
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    int res1=recursion(n-1);
    int res2=recursion(n-2);
    int sum=res1+res2;
    return sum;
}
    int fib(int n) {
        int ans=recursion(n);
        return ans;
        
    }
};
//Method 2:using Top-Down(Memorization)method
class Solution {
public:
int solveWithMemo(vector<int>&dp,int n)
{
    //base case
    if(n==0) return 0;
    if (n==1) return 1;
    if(dp[n]!=-1)
    return dp[n];
    int res1=solveWithMemo(dp,n-1);
    int res2=solveWithMemo(dp,n-2);
    int sum=res1+res2;
    //store sum value then return
    dp[n]=sum;
    return sum;
}
    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveWithMemo(dp,n);
        return ans;       
    }
};
//Method3:using Bottom-Up dp(Tabulation)method
class Solution {
public:
int solveWithBottomUp(int n)
{
    vector<int>dp(n+1,-1);
    //base case
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int res1=dp[i-1];
        int res2=dp[i-2];
        int sum=res1+res2;
        //store value
        dp[i]=sum;
    }
    return dp[n];
}
    int fib(int n) {
        //handle edge case
        if(n==0)
        return 0;
        int ans=solveWithBottomUp(n);
        return ans;       
    }
};
