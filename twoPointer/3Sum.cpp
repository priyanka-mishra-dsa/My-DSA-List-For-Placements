class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //3sum =(nums[i]+nums[first]+nums[second]==0)
        //convert 3 sum problem into 2 sum problem
        //sort the given array
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            //i fixed one value using for loop
            //handle dublicate value when we fix our 1st value
            if(i>0&& nums[i]==nums[i-1])
            continue;
           //apply 2 sum problem here 
           int first=i+1,second=n-1;
           while(first<second)
           {
              int sum=nums[i]+nums[first]+nums[second];
              if(sum==0)
              {
                ans.push_back({nums[i],nums[first],nums[second]});
                first++;
                second--;
                //handle duplicate for first pointer
              while(first<second&&nums[first]==nums[first-1])
              first++;
              //handle duplicate for second pointer
             while(first<second&&nums[second]==nums[second+1])
              second--;
              }
              else if(sum>0)
              {
                second--;
              }
              else if(sum<0)
              {
                first++;
              }

           }
        }
        return ans;


        
    }
};
