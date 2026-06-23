//using recursion
class Solution {
public:
int recursion(vector<int>&nums,int index)
{
    int n=nums.size();
    //base case
    if(index>=n)
    return 0;
    int robHouse=recursion(nums,index+2)+nums[index];
    int skipHouse=recursion(nums,index+1);
    int maxMoney=max(robHouse,skipHouse);
    return maxMoney;
}
    int rob(vector<int>& nums) {
        int ans=recursion(nums,0);
        return ans;
        
    }
};
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
//Tabulation
class Solution {
public:
int Tabulation(vector<int>&nums,int index)
{
    int n=nums.size();
    vector<int>dp(n+2,-1);
    //base case
    dp[n]=0;
    dp[n+1]=0;
    for(int i=n-1;i>=0;i--)
    {
       int robHouse=dp[i+2]+nums[i];
       int skipHouse=dp[i+1];
       int maxMoney=max(robHouse,skipHouse);
       dp[i]=maxMoney;
    }
    return dp[0];
}
    int rob(vector<int>& nums) {
        int ans=Tabulation(nums,0);
        return ans;
        
    }
};
