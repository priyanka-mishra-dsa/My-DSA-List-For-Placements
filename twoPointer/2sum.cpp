class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //store the original indices before sorting the array
        vector<pair<int,int>>index;
        for(int i=0;i<nums.size();i++)
        {
            index.push_back(make_pair(nums[i],i));
        }
        //sort the index array
        sort(index.begin(),index.end());
        //use 2 pointer
        int i=0,j=index.size()-1;
        vector<int>ans;
        while(i<j)
        {
            int sum=index[i].first+index[j].first;
            if(sum<target)
            {
                i++;
            }
            else if(sum>target)
            {
                j--;
            }
            else if(sum==target)
            {
              ans.push_back(index[i].second);
              ans.push_back(index[j].second);
              return ans;
            }
        }
        return {};
        
        
    }
};
