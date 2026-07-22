//recursion+memorization
class Solution {
public:
const int MOD=1e9+7;
int solve(int index,int arrLen,int steps,vector<vector<int>>&dp)
{
    //base case
    if(index<0 || index>=arrLen)
    return 0;
    if(steps==0)
    {
        if(index==0)
        return 1;
        else
        return 0;
    }
    if(dp[index][steps]!=-1)
    return dp[index][steps];
    //moves
    int right=solve(index+1,arrLen,steps-1,dp);
    int left=solve(index-1,arrLen,steps-1,dp);
    int stay=solve(index,arrLen,steps-1,dp);
    int totalWays=((right+left)%MOD+stay)%MOD;
    dp[index][steps]=totalWays;
    return totalWays;
}
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps+1);
        vector<vector<int>>dp(arrLen,vector<int>(steps+1,-1));
        int ans=solve(0,arrLen,steps,dp);
        return ans;   
    }
};
//Tabulation
class Solution {
public:
const int MOD=1e9+7;
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps+1);
        vector<vector<int>>dp(arrLen,vector<int>(steps+1,0));
        //base case
        dp[0][0]=1;
        for(int step=1;step<=steps;step++)
        {
            for(int index=0;index<arrLen;index++)
            {
                int right=0,left=0,stay=0;
                //right
                if(index+1<arrLen)
                 right=dp[index+1][step-1];
                //left
                if(index>0)
                 left=dp[index-1][step-1];
                //stay
                 stay=dp[index][step-1];
                int totalWays=((right+left)%MOD+stay)%MOD;
                dp[index][step]=totalWays;
            }
        }
        return dp[0][steps];
    }
};
