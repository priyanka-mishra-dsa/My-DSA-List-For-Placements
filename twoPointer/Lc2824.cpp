class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int first=0;
        int second=n-1;
        while(first<second) 
        {
            int sum=nums[first]+nums[second];
            if(sum<target)
            {
                count=count+(second-first);
                first++;
            }
            else if(sum>=target)
            {
                second--;
            }
        }
        return count;
    }
};
