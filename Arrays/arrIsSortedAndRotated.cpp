class Solution {
public:
    bool check(vector<int>& nums) {
        //if array is sorted and rotated
        //toh usme ek only one peak value hoga jiske next value less than hoga
        int peak=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            peak++;
        }
        if(peak>1)
        return false;
        else
        return true;
    }
};
