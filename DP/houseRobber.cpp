//Memorization dp
class Solution {
public:
int Memorization(vector<int>& nums,vector<int>&dp,int index)
{
    int n=nums.size();
    //base case
    if(index>=n)
    return 0;
    if(dp[index]!=-1)
    return dp[index];
    int robHouse=Memorization(nums,dp,index+2)+nums[index];
    int skipHouse=Memorization(nums,dp,index+1);
    int maxMoney=max(robHouse,skipHouse);
    //store the value
    dp[index]=maxMoney;
    return maxMoney;    
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=Memorization(nums,dp,0);
        return ans;   
    }
};
