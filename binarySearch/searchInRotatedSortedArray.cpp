class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(left<=right)
        {
          mid=left+(right-left)/2;
          if(nums[mid]==target)
          {
            return mid;
          }
          //check which half is sorted left or right
          //left half is sorted
          else if(nums[left]<=nums[mid])
          {
            //means left part is sorted from left to mid
            //now check that left to mid me target hai ya nhi (range me)
            if(nums[left]<=target && target<nums[mid])
            {
                //go left side target left me hi hai
                right=mid-1;
            }
            else
            {
                //go to right side
                left=mid+1;//[0,1,2]
            }
          }
          //right side is sorted
          else if(nums[right]>=nums[mid])
          {
            if(nums[right]>=target && target>nums[mid])
            {
                //target present hai mid to right ke range me
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
          }
        }
        return -1;
    }
};
