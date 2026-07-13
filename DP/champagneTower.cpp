//recursion+memorization
class Solution {
public:
double solve(int i,int j,int poured,vector<vector<double>>&dp)
{
    //handle invalid case
    if(i<0 || j<0||j>i)
    {
        return 0.0;
    }
    //base case
    if(i==0 && j==0)
    return poured;
    //
    if(dp[i][j]!=-1)
    return dp[i][j];
    //
    double top_left=max(0.0,(solve(i-1,j-1,poured,dp)-1)/2);
    double top_right=max(0.0,(solve(i-1,j,poured,dp)-1)/2);
    double total=top_left+top_right;
    //store
    dp[i][j]=total;
    return total;
}
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1,vector<double>(query_row+1,-1));
        double ans=solve(query_row,query_glass,poured,dp);//jiska find krna hai us index se start kr rahe hai
        if(ans>1.0)
        return 1.0;
        else
        return ans;   
    }
};
//Tabulation(Bottom-Up)
