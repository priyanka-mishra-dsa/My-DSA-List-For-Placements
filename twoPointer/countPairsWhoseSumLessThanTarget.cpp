class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int count=0;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum<target)
            {
                //count no of pairs(***imp)[1,2,3,4],target=6
                count=count+(j-i);
                //move pointer i
                i++;
            }
            else if(sum>=target)
            {
                //reduce the sum,move j pointer
                j--;
            }
        }
        return count;
    }
};
