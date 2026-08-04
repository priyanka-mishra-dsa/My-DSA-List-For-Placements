//recursion+memorization
#include<bits/stdc++.h>
using namespace std;
int solve(int index,vector<int>&ans,int n,vector<int>&dp)
{
        //base case
        if(index==n)
        return 1;
        //
        if(dp[index]!=-1)
        return dp[index];
        //
        int takeCurrIndex=solve(index+1,ans,n,dp);
        int skipCurrIndex=solve(index+1,ans,n,dp);
        int total=takeCurrIndex+skipCurrIndex;
        dp[index]=total;
        return total;
}
int main()
{
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        //1 dp 
        vector<int>dp(n,-1);
        int countNoOfsubsequence=solve(0,arr,n,dp);
        cout<<countNoOfsubsequence;
}
//Tabulation(bottom-up)
#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        //1 dp 
        vector<int>dp(n,0);
        //handle base case
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
                int takeCurrIndex=dp[i+1];
                int skipCurrIndex=dp[i+1];
                int total=takeCurrIndex+skipCurrIndex;
                dp[i]=total;
        }
        cout<< dp[0];
}
