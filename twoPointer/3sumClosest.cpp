class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int bestClosest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {
            int first=i+1,second=n-1;
            while(first<second)
            {
                int sum=nums[i]+nums[first]+nums[second];
                //update sum which is closest
                if(abs(sum-target)<abs(bestClosest-target))
                {
                    //wahi value update hoga jo target se closest hai
                    bestClosest=sum;
                }
                if(sum==target)
                {
                   //Return the sum of the three integers
                   return target; 
                }
                else if(sum<target)
                {
                    first++;
                }
                else
                {
                    second--;
                }
            }
        }
        return bestClosest;
        
    }
};
