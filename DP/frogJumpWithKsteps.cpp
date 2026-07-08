//recursion+memorization
class Solution {
  public:
  int solve(int index,vector<int>& arr,int n,int k,vector<int>&dp)
  {
      if(index==n-1)
      return 0;
      if(dp[index]!=-1)
      return dp[index];
      //jump k distance from index 0
      //we want min cost
      int minCost=INT_MAX;
      for(int i=1;i<=k;i++)
      {
          if(index+i<n)
          {
            int jumpKstep=solve(index+i,arr,n,k,dp)+abs(arr[index+i]-arr[index]);
            minCost=min(minCost,jumpKstep);
          }
      }
      dp[index]=minCost;
      return minCost;
  }
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,arr,n,k,dp);
        return ans;
    }
};
//Tabulation
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int index=i;
            int minCost=INT_MAX;
            //jump upto k steps
            for(int j=1;j<=k;j++)
            {
                if(index+j<n)
                {
                    int jumpKstep=dp[index+j]+abs(arr[index+j]-arr[index]);
                    minCost=min(minCost,jumpKstep);
                }
            }
            dp[index]=minCost;
        }
        return dp[0];
    }
};
