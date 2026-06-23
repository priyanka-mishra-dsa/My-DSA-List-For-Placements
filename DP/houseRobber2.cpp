//Recursion
class Solution {
public:
int recursion(vector<int>&nums,int start,int end)
{
    int n=nums.size();
    if(start>end)
    return 0;
    int robHouse=recursion(nums,start+2,end)+nums[start];
    int skipHouse=recursion(nums,start+1,end);
    int maxMoney=max(robHouse,skipHouse);
    return maxMoney;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        //handle edge case-> [1]
        if(n==1)
        return nums[0];
        int ans1=recursion(nums,0,n-2);
        int ans2=recursion(nums,1,n-1);
        return max(ans1,ans2);
        
    }
};
