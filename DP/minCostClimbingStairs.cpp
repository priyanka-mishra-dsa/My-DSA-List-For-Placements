//Using recursion
class Solution {
public:
int recursion(vector<int>&cost,int index)
{
    
    int n=cost.size();
    //base case
    if(index>=n)
    return 0;
    int climb1step=recursion(cost,index+1)+cost[index];
    int climb2step=recursion(cost,index+2)+cost[index];
    int mincost=min(climb1step,climb2step);
    return mincost;
}
    int minCostClimbingStairs(vector<int>& cost) {
        //start from index 0
        int cost1=recursion(cost,0);
        //start from index 1
        int cost2=recursion(cost,1);
        //return min cost among them
        int minCost=min(cost1,cost2);
        return minCost; 
    }
};
//Using memorization Dp
class Solution {
public:
int Memorization(vector<int>&cost,vector<int>&dp,int index)
{
    
    int n=cost.size();
    //base case
    if(index>=n)
    return 0;
    if(dp[index]!=-1)
    return dp[index];
    int climb1step=Memorization(cost,dp,index+1)+cost[index];
    int climb2step=Memorization(cost,dp,index+2)+cost[index];
    int mincost=min(climb1step,climb2step);
    //store the value
    dp[index]=mincost;
    return mincost;
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        //start from index 0
        int cost1=Memorization(cost,dp,0);
        //start from index 1
        int cost2=Memorization(cost,dp,1);
        //return min cost among them
        int minCost=min(cost1,cost2);
        return minCost; 
    }
};
//Using Tabulation
class Solution {
public:
int Tabulation(vector<int>&cost,int index)
{
    
    int n=cost.size();
    vector<int>dp(n+2,-1);
    //base case
    dp[n]=0;
    dp[n+1]=0;
    for(int i=n-1;i>=0;i--)
    {
        int climb1step=dp[i+1]+cost[i];
        int climb2step=dp[i+2]+cost[i];
        int mincost=min(climb1step,climb2step);
        //store the value
        dp[i]=mincost;
    }
    return dp[index];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //start from index 0
        int cost1=Tabulation(cost,0);
        //start from index 1
        int cost2=Tabulation(cost,1);
        //return min cost among them
        int minCost=min(cost1,cost2);
        return minCost; 
    }
};
