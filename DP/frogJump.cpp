//recursion+memorization
class Solution {
  public:
  int solve(int index,vector<int>& height,int n,vector<int>&dp)
  {
      //Base case
      if(index==n-1)
      return 0;
      //extra 
      if(dp[index]!=-1)
      return dp[index];
      //
      int jump1step=solve(index+1,height,n,dp)+abs(height[index+1]-height[index]);
      int jump2step=INT_MAX;
      if(index+2<n)
      jump2step=solve(index+2,height,n,dp)+abs(height[index+2]-height[index]);
      //
      int minCost=min(jump1step,jump2step);
      dp[index]=minCost;
      return minCost;
  }   
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,height,n,dp);
        return ans;
    }
};
//Tabulation
class Solution {
  public:  
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int jump1step=dp[i+1]+abs(height[i+1]-height[i]);
            int jump2step=INT_MAX;
            if(i+2<n)
            jump2step=dp[i+2]+abs(height[i+2]-height[i]);
            int minCost=min(jump1step,jump2step);
            dp[i]=minCost;
            
        }
        return dp[0];
        
    }
};
