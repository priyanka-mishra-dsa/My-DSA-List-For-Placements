//rec+memo
class Solution {
  public:
  int n;
  bool solve(int index,int sum,vector<int>& nums,vector<vector<int>>&dp)
  {
      //handle base case
      if(index==n)
      {
          if(sum==0)
          return true;
          else
          return false;
      }
      //extra chiz dp ka
      if(dp[index][sum]!=-1)
      return dp[index][sum];
      bool takeCurrIndex=false;
      if(nums[index]<=sum)
      {
          takeCurrIndex=solve(index+1,sum-nums[index],nums,dp);
      }
      bool skipCurrIndex=solve(index+1,sum,nums,dp);
      bool ans=takeCurrIndex || skipCurrIndex;
      dp[index][sum]=ans;
      return ans;
  }
    int minDifference(vector<int>& nums) {
         n=nums.size();
        //find total sum of array
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        //make 2d dp
        vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
        //check all possible subsequence of subset 1
        int ans=INT_MAX;
        for(int s1=0;s1<=totalSum;s1++)
        {
            if(solve(0,s1,nums,dp)==true)
            {
                int s2=totalSum-s1;
                int diff=abs(s1-s2);
                ans=min(ans,diff);
            }
        }
        return ans;
    }
};
