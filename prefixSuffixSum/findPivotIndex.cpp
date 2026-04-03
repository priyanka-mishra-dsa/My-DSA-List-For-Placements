class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //using prefix sum
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int preSum=0;
        for(int i=0;i<n;i++)
        {
            int leftSum=preSum;
            int rightSum=sum-nums[i]-leftSum;
            if(leftSum==rightSum)
            return i;
            preSum=preSum+nums[i];
        }
        return -1;
        
    }
};
