//Recursion
class Solution {
public:
int recursion(vector<int>&nums,int start,int end)
{
    int n=nums.size();
    if(start>end)
    return 0;
    int robHouse=recursion(nums,start+2,end)+nums[start];
    int skipHouse=recursion(nums,start+1,end);
    int maxMoney=max(robHouse,skipHouse);
    return maxMoney;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        //handle edge case-> [1]
        if(n==1)
        return nums[0];
        int ans1=recursion(nums,0,n-2);
        int ans2=recursion(nums,1,n-1);
        return max(ans1,ans2);
        
    }
};
//Memorization
class Solution {
public:
int Memorization(vector<int>&nums,int start,vector<int>&dp,int end)
{
    int n=nums.size();
    //base case
    if(start>end)
    return 0;
    //dp main point
    if(dp[start]!=-1)
    return dp[start];
    int robHouse=Memorization(nums,start+2,dp,end)+nums[start];
    int skipHouse=Memorization(nums,start+1,dp,end);
    int maxMoney=max(robHouse,skipHouse);
    //store the value first then return
    dp[start]=maxMoney;
    return maxMoney;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        //handle edge case-> [1]
        if(n==1)
        return nums[0];
        //use dp for optimization
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans1=Memorization(nums,0,dp1,n-2);
        int ans2=Memorization(nums,1,dp2,n-1);
        return max(ans1,ans2);
        
    }
};
//Tabulation
class Solution {
public:
int Tabulation(vector<int>&nums,int start,int end)
{
    int n=nums.size();
    vector<int>dp(n+2,-1);
    //base case
    dp[end+1]=0;
    dp[end+2]=0;
    for(int i=end;i>=start;i--)
    {
        int robHouse=dp[i+2]+nums[i];
        int skipHouse=dp[i+1];
        int maxMoney=max(robHouse,skipHouse);
        //store the value first then return
        dp[i]=maxMoney;
    }
    return dp[start];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        //handle edge case-> [1]
        if(n==1)
        return nums[0];
        //use dp for optimization
        int ans1=Tabulation(nums,0,n-2);
        int ans2=Tabulation(nums,1,n-1);
        return max(ans1,ans2);    
    }
};
