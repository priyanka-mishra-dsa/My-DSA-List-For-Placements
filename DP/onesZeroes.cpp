//rec+memorization
class Solution {
public:
int n1;
int solve(int index,int ones,int zeroes,vector<string>& nums, int m, int n,vector<vector<vector<int>>>&dp)
{
    //handle base case
    if(index==n1)
    {
        if(zeroes<=m && ones<=n)
        {
            return 0;
        }
        else
        return INT_MIN;
    }
    //invalid subsequence
    if(zeroes>m || ones>n)
    return INT_MIN;
    //
    if(dp[index][ones][zeroes]!=-1)
    return dp[index][ones][zeroes];
    //
    string ele=nums[index];
    int count0=0,count1=0;
    for(int i=0;i<ele.size();i++)
    {
        if(ele[i]=='0')
        count0++;
        else
        count1++;
    }
    int take=solve(index+1,ones+count1,zeroes+count0,nums,m,n,dp);
    if(take!=INT_MIN)
    take=1+take;
    int skip=solve(index+1,ones,zeroes,nums,m,n,dp);
    int ans=max(take,skip);
    dp[index][ones][zeroes]=ans;
    return ans;
}
    int findMaxForm(vector<string>& nums, int m, int n) {
        n1=nums.size();
        vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        int ans=solve(0,0,0,nums,m,n,dp);
        return ans;  
    }
};
//Tabulation
