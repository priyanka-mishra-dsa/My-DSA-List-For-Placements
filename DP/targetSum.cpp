//rec+memo
class Solution {
public:
int n;
int totalSum;
int solve(int index,int sum,int target,vector<int>&nums,vector<vector<int>>&dp)
{
    //handle base case
    if(index==n)
    {
        if(sum==target)
        {
            return 1;
        }
        else
        return 0;
    }
    //dp
    if(dp[index][sum+totalSum]!=-1)
    return dp[index][sum+totalSum];
    //
    int add=solve(index+1,sum+nums[index],target,nums,dp);
    int sub=solve(index+1,sum-nums[index],target,nums,dp);
    int count=add+sub;
    dp[index][sum+totalSum]=count;
    return count;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        //find total sum
        totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(2*totalSum+1,-1));
        int ans=solve(0,0,target,nums,dp);
        return ans;
    }
};
