//rec+memo
class Solution {
public:
int n;
int solve(int index,int sum,vector<int>& nums,vector<vector<int>>&dp)
{
    //handle base case
    if(index==n)
    {
        if(sum==0)
        {
            return 0;
        }
        else
        return INT_MIN;
    }
    if(dp[index][sum]!=-1)
    return dp[index][sum];
    //take or not take
    int takeCurrIndex=INT_MIN;
    if(nums[index]<=sum)
    {
        takeCurrIndex=solve(index+1,sum-nums[index],nums,dp);
        if(takeCurrIndex!=INT_MIN)
        {
            takeCurrIndex=1+takeCurrIndex;
        }
    }
    int skipCurrIndex=solve(index+1,sum,nums,dp);
    int maxLen=max(takeCurrIndex,skipCurrIndex);
    dp[index][sum]=maxLen;
    return maxLen;
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=INT_MIN;
        ans=solve(0,target,nums,dp); 
        if(ans==INT_MIN)
        return -1;    
        return ans;  
    }
};
