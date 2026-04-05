//kadane's Algorithum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's algo==jab bhi prefixsum ki value neg arhi hai make it that value as 0
        int maxSum=INT_MIN,prefixSum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum=prefixSum+nums[i];
            maxSum=max(prefixSum,maxSum);
            //if prefix sum become negative then 
            if(prefixSum<0)
            {
                //set prefix sum as 0
               prefixSum=0;
            }
        }
        return maxSum;      
    }
};
