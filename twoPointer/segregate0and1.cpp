class Solution {
  public:
    void segregate0and1(vector<int> &nums) {
        int n=nums.size();
        int first=0;
        int second=n-1;
        while(first<second)
        {
            if(nums[first]==0)
            {
                first++;
            }
            else if(nums[second]==0)
            {
                swap(nums[first],nums[second]);
                //move both pointer
                first++;
                second--;
            }
            else if(nums[second]==1)
            {
                second--;
            }
        }
    }
};
