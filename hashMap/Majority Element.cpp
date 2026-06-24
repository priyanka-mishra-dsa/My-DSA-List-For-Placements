//Using unordered map for count the freq
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        //count freq of each element
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        //check in map for n/2 freq wala element
        for(auto it:m)
        {
            if(it.second>n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};
//Boyer Moore voting algorithum
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,candidate;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                candidate=nums[i];
            }
            if(nums[i]==candidate)
            count++;
            else if(nums[i]!=candidate)
            count--;
        }
        return candidate;
    }
};
