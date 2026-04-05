class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //you need to take negative no also so you need to calcualte minsum of subarray
        int maxSum=INT_MIN,minSum=INT_MAX,currMaxSum=0,currMinSum=0;
        for(int i=0;i<nums.size();i++)
        {
            //find maxsum of subarray using kadane's
            currMaxSum=currMaxSum+nums[i];
            maxSum=max(maxSum,currMaxSum);
            //if value becomes negative reset it as zero
            if(currMaxSum<0)
            currMaxSum=0;
            //find minsum of subarray using kadane's
            currMinSum=currMinSum+nums[i];
            minSum=min(minSum,currMinSum);
            //if value becomes positive reset it as zero
            if(currMinSum>0)
            currMinSum=0;
        }
        return max(maxSum,abs(minSum));
        
    }
};
