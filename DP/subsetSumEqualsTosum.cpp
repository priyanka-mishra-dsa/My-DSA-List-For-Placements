//recursion+memorization
class Solution {
  public:
  bool solve(int index,vector<int>& arr, int sum,int n,vector<vector<int>>&dp)
  {
      //base case
      if(index==n)
      {
          if(sum==0)
          return true;
          else
          return false;
      }
      //dp
      if(dp[index][sum]!=-1)
      return dp[index][sum];
      //
      bool takeCurrIndex=false;
      if(arr[index]<=sum)
      takeCurrIndex=solve(index+1,arr,sum-arr[index],n,dp);
      bool skipCurrIndex=solve(index+1,arr,sum,n,dp);
      bool ans=takeCurrIndex || skipCurrIndex;
      //store before return
      dp[index][sum]=ans;
      return ans;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        //index and sum both are changing so we will take 2d dp
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        bool ans=solve(0,arr,sum,n,dp);
        return ans;
    }
};
//Bottom-up
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        //index and sum both are changing so we will take 2d dp
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        //handle base case
        dp[n][0]=true;
        for(int index=n-1;index>=0;index--)
        {
            for(int target=0;target<=sum;target++)
            {
                bool takeCurrIndex=false;
                if(arr[index]<=target)
                {
                    takeCurrIndex=dp[index+1][target-arr[index]];
                }
                bool skipCurrIndex=dp[index+1][target];
                bool ans=takeCurrIndex || skipCurrIndex;
                //store
                dp[index][target]=ans;
            }
        }
        return dp[0][sum];
    }
};
