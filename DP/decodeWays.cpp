//recursion+memorization
class Solution {
public:
int solve(int index,string &s,int n,vector<int>&dp)
{
    //Base case
    if(index==n)
    return 1;
    if(s[index]=='0')
    return 0;
    //extra
    if(dp[index]!=-1)
    return dp[index];
    int count=0;
    //taken only one digit
    count=solve(index+1,s,n,dp);
    //take 2 digit
    if(index+1<n &&s[index]=='1')
    {
        count=count+solve(index+2,s,n,dp);
    }
    else if(index+1<n && s[index]=='2' && s[index+1]<='6')
    {
        count=count+solve(index+2,s,n,dp);
    }
    //store
    dp[index]=count;
    return count;
}
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        int ans=solve(0,s,n,dp);
        return ans;    
    }
};
//Tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            //handle edge case
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            int count=0;
            //take only one digit
            count=dp[i+1];
            //take 2 digit
            if(i+1<n && s[i]=='1')
            count=count+dp[i+2];
            else if(i+1<n && s[i]=='2' && s[i+1]<='6')
            {
                count=count+dp[i+2];
            }
            dp[i]=count;        
        } 
        return dp[0];
    }
};
