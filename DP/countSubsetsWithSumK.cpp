//rec+memo
class Solution {
  public:
  int n;
  int solve(int index,int sum,vector<int>&nums,vector<vector<int>>&dp)
  {
      //handle base case
      if(index==n)
      {
        if(sum==0)
        return true;
        else
        return false;
      }
      //
      if(dp[index][sum]!=-1)
      return dp[index][sum];
      //
      int takeCurrIndex=0;
      if(nums[index]<=sum)
      {
          takeCurrIndex=solve(index+1,sum-nums[index],nums,dp);
      }
      int skipCurrIndex=solve(index+1,sum,nums,dp);
      int ans=takeCurrIndex+skipCurrIndex;
      dp[index][sum]=ans;
      return ans;
  }
    int perfectSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int count=solve(0,target,nums,dp);
        return count;
    }
};
