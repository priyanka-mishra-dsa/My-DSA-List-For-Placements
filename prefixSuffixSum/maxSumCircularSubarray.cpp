//Kadane's Algorithum
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //we have to handle 2 cases here
        //1.Kadane's algo for linear subarray(maxSum)
        //2.for circular subarray add first +last element of array
        //(maxSumforCir=totalsum-minsum of subarray)

        int maxSum=INT_MIN,minSum=INT_MAX,prefixSum1=0,prefixSum2=0,totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            //calculate totalsum
            totalSum=totalSum+nums[i];
            //find maxsubarray
            prefixSum1=prefixSum1+nums[i];
            maxSum=max(maxSum,prefixSum1);
            if(prefixSum1<0)
            {
                prefixSum1=0;
            }
            //find min subarray sum
            prefixSum2=prefixSum2+nums[i];
            minSum=min(minSum,prefixSum2);
            if(prefixSum2>0)
            {
                prefixSum2=0;
            }

        }
        //if all the element of arr is negative[-3,-2,-3]
        if(maxSum<0)
        {
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);
        
    }
};
