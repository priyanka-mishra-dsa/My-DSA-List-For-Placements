//rec+memo
//tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        //find total sum
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        if(totalSum%2!=0)
        return false;
        int target=totalSum/2;
        //take 2d dp
        vector<vector<int>>dp(n+1,vector<int>(target+1,false));
        //handle base case
        dp[n][0]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(int targeti=1;targeti<=target;targeti++)
            {
                bool takeCurrIndex=false;
                if(nums[i]<=targeti)
                {
                    takeCurrIndex=dp[i+1][targeti-nums[i]];
                }
                bool skipCurrIndex=dp[i+1][targeti];
                bool ans=takeCurrIndex || skipCurrIndex;
                dp[i][targeti]=ans;
            }
        }
        return dp[0][target];
    }
};
