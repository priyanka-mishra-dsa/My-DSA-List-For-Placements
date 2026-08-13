class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        //handle edge case
        if(n<3)
        return 0;
        //if i want to make a triangle using 3 values
        //i have to satisfy condition->a+b>c
        //it proves that c should be greater than a and b

        sort(nums.begin(),nums.end());//[2,3,4,4]
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            int c=nums[i];
            //now you can take 2 pointer
            int first=0,second=i-1;
            while(first<second)
            {
                int sum=nums[first]+nums[second];
                if(sum<=c)
                {
                    first++;
                }
                else if(sum>c)
                {
                    count=count+(second-first);
                    second--;
                }
            }
        }
        return count;
    }
};
