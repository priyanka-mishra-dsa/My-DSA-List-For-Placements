//using recursion
//optimize using dp
//memorization
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n,vector<int>&dp)
{
        if(n==0) return 0;
        if(n==1) return 1;
        //fibonacci find krenge
        if(dp[n]!=-1)
        return dp[n];
        int take1step=fibonacci(n-1,dp);
        int take2step=fibonacci(n-2,dp);
        int sum=take1step+take2step;
        dp[n]=sum;
        return sum;
}
int main()
{
        int n;
        cin>>n;
        int fibSum=0;
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++)
        {
                fibSum=fibSum+fibonacci(i,dp);
        }
        cout<<fibSum;
}
