class Solution {
  public:
    bool isProduct(vector<int>& nums, long long target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int first=0;
        int second=n-1;
        while(first<second)
        {
            long long product=1LL*nums[first]*nums[second];
            if(product<target)
            {
                first++;
            }
            else if(product>target)
            {
                second--;
            }
            else if(product==target)
            {
                return true;
            }
        }
        return false;
    }
};
