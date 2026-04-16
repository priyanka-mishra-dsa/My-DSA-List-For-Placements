class Solution {
public:
    int search(vector<int>& nums, int target) {
        //before applying binary search check that array is sorted or not
        //take 2 pointer
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        while(start<=end)
        {
            //find mid index
            mid=start+(end-start)/2;
            if(nums[mid]<target)
            {
                //go to right side(move start pointer)
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                //go to left side(move end pointer)
                end=mid-1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
        }
        return -1;    
    }
};
