class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //sorted in non dec order==duplicate element is present adjcent pr
        //just compare with prev element to find duplicate element
        // take two pointer which is adjacent to each other
        int i=0,j=1;
        while(j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                //skip j pointer wala element because it is duplicate
                j++;
            }
            else if(nums[i]!=nums[j])
            {
                //i pointer ko vacent space pr lao
                i++;
                nums[i]=nums[j];
            }
        }
        //tell me no of unique element present in the array
        return i+1;    
    }
};
