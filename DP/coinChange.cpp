//recursion+memorizaion
class Solution {
public:
int solve(int amount,vector<int>& coins,int n,vector<int>&dp)
{
    //base case
    if(amount==0)
    return 0;
    if(amount<0)//we cross our amount wala point
    return INT_MAX;
    //we want min coins to get amount
    int minCoin=INT_MAX;
    //extra 
    if(dp[amount]!=-1)
    return dp[amount];
    for(int i=0;i<n;i++)
    {
        int ans=solve(amount-coins[i],coins,n,dp);
        if(ans!=INT_MAX)
        {
            minCoin=min(minCoin,1+ans);
        }
    }
    //store the minCoin value
    dp[amount]=minCoin;
    return minCoin;
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=solve(amount,coins,n,dp);
        return ans==INT_MAX?-1:ans;   
    }
};
//Tabulation dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        //base case
        dp[0]=0;
        for(int amo=1;amo<=amount;amo++)
        {
            int minCoins=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(amo>=coins[i] && dp[amo-coins[i]]!=INT_MAX)
                {
                    minCoins=min(minCoins,1+dp[amo-coins[i]]);
                }
            }
            dp[amo]=minCoins;
        }
        return (dp[amount]==INT_MAX?-1:dp[amount]);
    }
};
