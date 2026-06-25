//Using unordered map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {
            if(it.second>n/3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
//For optimizing space from 0(n) to 0(1)
//we will use boyer moore voting algorithum
