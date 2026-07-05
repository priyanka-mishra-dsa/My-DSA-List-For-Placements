class Solution {
public:
 int HouseRob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--)
        {
            int robHouse=dp[i+2]+nums[i];
            int skipHouse=dp[i+1];
            int maxMoney=max(robHouse,skipHouse);
            dp[i]=maxMoney;
        }
        return dp[0];
    }
    int deleteAndEarn(vector<int>& nums) {
        //step 1:convert nums into earn array
        int n=nums.size();
        int maxVal=0;
        for(int i=0;i<n;i++)
        {
            maxVal=max(nums[i],maxVal);
        }
        vector<int>earn(maxVal+1,0);
        for(int i=0;i<n;i++)
        {
            earn[nums[i]]=earn[nums[i]]+nums[i];
        }
        //pass earn vector into house rob function
        int ans=HouseRob(earn);
        return ans;
    }
};
