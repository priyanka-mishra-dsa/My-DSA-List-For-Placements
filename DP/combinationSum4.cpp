//recursion+memorization
class Solution {
public:
int solve(vector<int>& nums, int target,int n,vector<int>&dp)
{
    //base case
    if(target==0)
    return 1;
    if(target<0)
    return 0;
    if(dp[target]!=-1)
    return dp[target];
    int countTotalCombinations=0;
    for(int i=0;i<n;i++)
    {
       countTotalCombinations+=solve(nums,target-nums[i],n,dp);
    }
    dp[target]=countTotalCombinations;
    return countTotalCombinations;
}
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        int ans=solve(nums,target,n,dp);
        return ans;    
    }
};
//Tabulation
