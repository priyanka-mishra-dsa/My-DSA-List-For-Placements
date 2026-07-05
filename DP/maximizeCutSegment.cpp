//Using recursion
class Solution {
  public:
  int solve(int n, int x, int y, int z)
  {
      //base case
      if(n==0) return 0;
      if(n<0) return INT_MIN;
      int cutInLenX=solve(n-x,x,y,z);
      int cutInLenY=solve(n-y,x,y,z);
      int cutInLenZ=solve(n-z,x,y,z);
      int maxSegment=max({cutInLenX,cutInLenY,cutInLenZ});
      if(maxSegment!=INT_MIN)
      maxSegment=1+maxSegment;
      
      return maxSegment;
  }
    int maximizeCuts(int n, int x, int y, int z) {
        int ans=solve(n,x,y,z);
        return ans;
        if(ans<0)
        return 0;
    }
};
//using memorization dp
class Solution {
  public:
  int solve(int n, int x, int y, int z,vector<int>&dp)
  {
      //base case
      if(n==0) return 0;
      if(n<0) return INT_MIN;
      //extra logic of dp
      if(dp[n]!=-1)
      {
          return dp[n];
      }
      int cutInLenX=solve(n-x,x,y,z,dp);
      int cutInLenY=solve(n-y,x,y,z,dp);
      int cutInLenZ=solve(n-z,x,y,z,dp);
      int maxSegment=max({cutInLenX,cutInLenY,cutInLenZ});
      if(maxSegment!=INT_MIN)
      maxSegment=1+maxSegment;
      //store maxsegment for every value of n then return
      dp[n]=maxSegment;
      return maxSegment;
  }
    int maximizeCuts(int n, int x, int y, int z) {
        vector<int>dp(n+1,-1);
        int ans=solve(n,x,y,z,dp);
        if(ans<0)
        return 0;
        else
        return ans;
    }
};
//using tabulation dp
