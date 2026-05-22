class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            //handle duplicate value
            if(nums[left]==nums[mid] && nums[right]==nums[mid])
            {
                left++;
                right--;
            }
            //left side is sorted
            else if(nums[left]<=nums[mid])
            {
                //target b/w range or not ([left,mid])
                if(nums[left]<=target && target<nums[mid])
                {
                    //go to left
                    right=mid-1;
                }
                else
                left=mid+1;
            }
            else if(nums[right]>=nums[mid])
            {
                //target b/w range[mid,right]
                if(target>nums[mid] && nums[right]>=target)
                {
                    left=mid+1;
                }
                else
                right=mid-1;
            }
        }
        return false;
    }
};
