class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //solve using 2 pointer
        //assign a pointer which will decide the position of zero
        int zeroPosition=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
               continue;
            }
            else if(nums[i]!=0)
            {
                swap(nums[i],nums[zeroPosition]);
                zeroPosition++;
            }
        }
    }
};
