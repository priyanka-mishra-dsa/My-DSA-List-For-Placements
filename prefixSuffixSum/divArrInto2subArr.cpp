class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        //apply prefix and suffix sum
        //find total sum;
        int n=arr.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
          totalSum=totalSum+arr[i];
        }
        //when pefix sum and suffix equal aata hai mtlb 2 subarry me divide kr sakte hai
        int preSum=0;
        for(int i=0;i<n;i++)
        {
            preSum=preSum+arr[i];
            //calculate suffix sum
            int sufSum=totalSum-preSum;
            if(preSum==sufSum)
            return true;
        }
        return false;
    }
};
