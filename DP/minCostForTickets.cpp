//recursion+memorization
class Solution {
public:
int solve(int index,vector<int>& days, vector<int>& costs,int n,vector<int>&dp)
{
    //base case
    if(index==n)
    return 0;
    //extra
    if(dp[index]!=-1)
    return dp[index];
    //cost for buy 1 day pass for current index
    int cost_1=costs[0]+solve(index+1,days,costs,n,dp);
    //cost for buy 7 day pass for current index
    int j=index;
    int max_day=days[j]+7;
    while(j<n && days[j]<max_day)
    {
        j++;
    }
    int cost_7=costs[1]+solve(j,days,costs,n,dp);
    //cost for buy 30 day pass for current index
    int k=index;
    int max_days=days[k]+30;
    while(k<n && days[k]<max_days)
    {
        k++;
    }
    int cost_30=costs[2]+solve(k,days,costs,n,dp);
    int minCost=min({cost_1,cost_7,cost_30});
    //store before returning mincost
    dp[index]=minCost;
    return minCost;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,days,costs,n,dp);
        return ans;    
    }
};
//Tabulation
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        for(int index=n-1;index>=0;index--) 
        {
           //cost for buy 1 day pass for current index
           int cost_1=costs[0]+dp[index+1];
           //cost for buy 7 day pass for current index
           int j=index;
           int max_day=days[j]+7;
           while(j<n && days[j]<max_day)
           j++;
           int cost_7=costs[1]+dp[j];
           //cost for buy 30 day pass for current index
           int k=index;
           max_day=days[k]+30;
           while(k<n && days[k]<max_day)
           k++;
           int cost_30=costs[2]+dp[k];
           int minCost=min({cost_1,cost_7,cost_30});
           //store
           dp[index]=minCost;
        }
        return dp[0];
    }
};
