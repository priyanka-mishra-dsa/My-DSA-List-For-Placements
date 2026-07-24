//recursion+memorization
class Solution {
public:
int solve(int row,int sum,vector<vector<int>>& mat, int target,int m,int n,vector<vector<int>>&dp)
{
    //base case
    if(row==m)
    {
        //find absoulte sum
       return abs(sum-target);
    }
    if(dp[row][sum]!=-1)
    return dp[row][sum];
    int minDiff=INT_MAX;
    //check each element of row
    for(int col=0;col<n;col++)
    {
        int ans=solve(row+1,sum+mat[row][col],mat,target,m,n,dp);
        minDiff=min(ans,minDiff);
    }
    dp[row][sum]=minDiff;
    return minDiff;
}
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        //each time row as well as sum is changing ->take 2d dp
        //for handle sum state first we have to calculate max value of matrix
        int maxElemSum=0;
        for(int i=0;i<m;i++)
        {
            int maxele=0;
            for(int j=0;j<n;j++)
            {
                maxele=max(mat[i][j],maxele);
            }
            maxElemSum=maxElemSum+maxele;
        }
        //sum state range->[0,maxElemSum]
        vector<vector<int>>dp(m,vector<int>(maxElemSum+1,-1));
        //start from 1st row
         int ans=solve(0,0,mat,target,m,n,dp);
        return ans;    
    }
};
