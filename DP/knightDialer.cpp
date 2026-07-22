//recursion+memorization
class Solution {
public:
const int MOD=1e9+7;
//knight moves from each digit
vector<vector<int>>moves={
    {4,6},//0
    {6,8},//1
    {7,9},//2
    {4,8},//3
    {3,0,9},//4
    {},//5
    {1,0,7},//6
    {2,6},//7
    {1,3},//8
    {4,2},//9
};
int solve(int digit,int movesLeft,vector<vector<int>>&dp)
{
    //base case
    if(movesLeft==0)
    return 1;
    if(dp[digit][movesLeft]!=-1)
    return dp[digit][movesLeft];
    //find digit
    long long totalWays=0;
    for(int i=0;i<moves[digit].size();i++)
    {
        int nextDigit=moves[digit][i];
        totalWays=(totalWays+solve(nextDigit,movesLeft-1,dp))%MOD;
    }
    dp[digit][movesLeft]=totalWays;
    return totalWays;
}
    int knightDialer(int n) {
         int movesLeft=n-1;
         vector<vector<int>>dp(10,vector<int>(movesLeft+1,-1));
         //for each cell we have to check
         long long ans=0;
         for(int cell=0;cell<=9;cell++)
         {
            ans=(ans+solve(cell,movesLeft,dp))%MOD;
         }
        return ans;   
    }
};
//Tabulation
