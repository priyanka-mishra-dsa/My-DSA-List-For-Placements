//recursion+memorization
class Solution {
public:
long long solve(int index,vector<vector<int>>& questions,int n,vector<long long>&dp)
{
    if(index>=n)
    return 0;
    //extra logic in dp
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    long long solveQue=solve(index+questions[index][1]+1,questions,n,dp)+questions[index][0];
    long long skipQue=solve(index+1,questions,n,dp);
    long long maxPoints=max(solveQue,skipQue);
    //store maxpoints for that index
    dp[index]=maxPoints;
    return maxPoints;
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        long long ans=solve(0,questions,n,dp);
        return ans;    
//Tabulation
class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n=ques.size();
        vector<long long>dp(n+1,0);
        //Base case
        dp[n]=0;
        for(int index=n-1;index>=0;index--)
        {
            long long solveQue=ques[index][0];
            long long nextQueIndex=index+ques[index][1]+1;
            if(nextQueIndex<n)
            {
                solveQue=solveQue+dp[nextQueIndex];
            }
            long long skipQue=dp[index+1];
            long long maxPoint=max(solveQue,skipQue);
            //store
            dp[index]=maxPoint;
        }
        return dp[0];    
    }
};
