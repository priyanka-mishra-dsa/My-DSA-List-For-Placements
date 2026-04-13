class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //sort the array
        //4 sum=fix 1st value using first loop and fix 2nd val using 2nd loop and then inside 
        //2nd loop apply 2 sum logic.
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            //first handle duplicate
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<n-2;j++)
            {
                //handle duplicate
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                //apply 2 sum concept here
                int first=j+1,second=n-1;
                while(first<second)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[first]+nums[second];
                    if(sum==target)
                    {
                      ans.push_back({nums[i],nums[j],nums[first],nums[second]});
                      first++;
                      second--;
                      //handle duplicate
                      while(first<second && nums[first]==nums[first-1])
                      first++;
                      while(first<second && nums[second]==nums[second+1])
                      second--;
                    }
                    else if(sum<target)
                    {
                        first++;
                    }
                    else{
                        second--;
                    }
                }
            }
        }
        return ans;
        
    }
};
