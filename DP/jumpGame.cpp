//recursion+memorization
class Solution {
public:
int solve(int index,vector<int>&nums,int n,vector<int>&dp)
{
    //base case
    if(index==n-1)
    return true;
    if(dp[index]!=-1)
    return dp[index];
    int maxJump=nums[index];
    for(int i=1;i<=maxJump;i++)
    {
        //check that jump out of bound na jaye
        if(index+i<n)
        {
            if(solve(index+i,nums,n,dp)==true)
            {
                dp[index]=true;
                return dp[index];
            }
        }
    }
    dp[index]=false;
    return dp[index];
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,nums,n,dp);
        return ans;    
    }
};
//Tabulation
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,false);
        dp[n-1]=true;
        for(int index=n-1;index>=0;index--)
        {
            int maxJump=nums[index];
            for(int jump=1;jump<=maxJump;jump++)
            {
                if(index+jump<n)
                {
                    if(dp[index+jump]==true)
                    {
                        dp[index]=true;     
                    }
                }
            }
        }
        return dp[0];
    }
};
