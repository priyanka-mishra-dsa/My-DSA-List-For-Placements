class Solution {
public:
    int findMin(vector<int>& nums) {
        //after rotation first we have to check that
        //min is present at left side or right side
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(left<right)
        {
          mid=left+(right-left)/2;
          if(nums[right]<nums[mid])
          {
            //means min is present right side
            //go right
            left=mid+1;
          }
          //go to left
          else if(nums[right]>=nums[mid])
          {
            //means min present on left side
            //go to left
            // right=mid-1;because mid bhi min value ho skta hai
            right=mid;
          }
        }
        //at last left and right present on the min value
        //so return any one
        return nums[right];
    }
};
