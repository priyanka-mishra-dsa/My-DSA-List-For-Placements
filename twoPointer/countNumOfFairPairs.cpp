class Solution {
public:
int n;
long long countLessThanEqual(vector<int>& nums,int target)
{
    int first=0;
    int second=n-1;
    long long count=0;
    while(first<second)
    {
        long long sum=nums[first]+nums[second];
        if(sum<=target)
        {
            count=count+(second-first);
            first++;
        }
        else
        second--;
    }
    return count;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        n=nums.size();
        sort(nums.begin(),nums.end());  //[0,1,4,4,5,7]
        long long up=countLessThanEqual(nums,upper);
        long long low=countLessThanEqual(nums,lower-1);
        long long count=up-low;
        return count;
    }
};
